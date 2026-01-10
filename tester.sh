#!/bin/bash

# Configuration
PUSH_SWAP="./push_swap"
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# Vérification de la présence de l'exécutable
if [ ! -f "$PUSH_SWAP" ]; then
    echo -e "${RED}[ERREUR] Le fichier $PUSH_SWAP est introuvable.${NC}"
    echo "Veuillez compiler votre projet (make) avant de lancer ce test."
    exit 1
fi

# Fonction pour afficher les titres
print_header() {
    echo -e "\n${BLUE}=========================================${NC}"
    echo -e "${BLUE}   $1${NC}"
    echo -e "${BLUE}=========================================${NC}"
}

# Fonction pour vérifier si une liste est triée (via Python pour la fiabilité)
check_is_sorted() {
    # $1 est la liste des nombres, $2 est la sortie de push_swap
    python3 -c "
import sys
try:
    nums = [int(x) for x in '$1'.split()]
    ops = '$2'.strip().split('\n')
    if ops == ['']: ops = []
    
    a = nums[:]
    b = []
    
    for op in ops:
        if op == 'sa':
            if len(a) > 1: a[0], a[1] = a[1], a[0]
        elif op == 'sb':
            if len(b) > 1: b[0], b[1] = b[1], b[0]
        elif op == 'ss':
            if len(a) > 1: a[0], a[1] = a[1], a[0]
            if len(b) > 1: b[0], b[1] = b[1], b[0]
        elif op == 'pa':
            if b: a.insert(0, b.pop(0))
        elif op == 'pb':
            if a: b.insert(0, a.pop(0))
        elif op == 'ra':
            if len(a) > 1: a.append(a.pop(0))
        elif op == 'rb':
            if len(b) > 1: b.append(b.pop(0))
        elif op == 'rr':
            if len(a) > 1: a.append(a.pop(0))
            if len(b) > 1: b.append(b.pop(0))
        elif op == 'rra':
            if len(a) > 1: a.insert(0, a.pop())
        elif op == 'rrb':
            if len(b) > 1: b.insert(0, b.pop())
        elif op == 'rrr':
            if len(a) > 1: a.insert(0, a.pop())
            if len(b) > 1: b.insert(0, b.pop())
            
    if a == sorted(nums) and len(b) == 0:
        print('OK')
    else:
        print('KO')
except:
    print('KO_SCRIPT_ERROR')
"
}

# --- PARTIE 1 : GESTION D'ERREURS ---
print_header "TESTS DE GESTION D'ERREURS"

check_error() {
    local test_name="$1"
    local args="$2"
    echo -ne "Test: $test_name ... "
    output=$($PUSH_SWAP $args 2>&1)
    
    if echo "$output" | grep -q "Error"; then
        echo -e "${GREEN}PASS (Error bien affiché)${NC}"
    elif [ -z "$output" ]; then
         # Certains sujets demandent rien, d'autres Error, à adapter selon ta version du sujet
         echo -e "${YELLOW}PASS (Rien affiché)${NC}" 
    else
        echo -e "${RED}FAIL (Sortie: $output)${NC}"
    fi
}

check_error "Non-numérique" "1 2 coucou 4"
check_error "Doublons" "1 2 3 2 4"
check_error "Max Int + 1" "2147483648"
check_error "Min Int - 1" "-2147483649"
check_error "Seulement des espaces" "   "

# --- PARTIE 2 : TESTS FONCTIONNELS ---
print_header "TESTS DE TRI (Précision & Performance)"

run_test() {
    local count=$1
    local limit=$2
    
    # Génération de nombres aléatoires uniques via shuf
    # Note: shuf est standard sur Linux. Sur Mac, utiliser ruby ou python si shuf absent.
    ARGS=$(shuf -i 0-5000 -n $count | tr '\n' ' ')
    
    # Exécution
    INSTRUCTIONS=$($PUSH_SWAP $ARGS)
    NB_COUPS=$(echo "$INSTRUCTIONS" | wc -l)
    
    # Cas particulier : si 0 coups (liste déjà triée ou vide), wc -l renvoie 1 (ligne vide) ou 0
    if [ -z "$INSTRUCTIONS" ]; then NB_COUPS=0; fi

    # Vérification du tri
    CHECK_RESULT=$(check_is_sorted "$ARGS" "$INSTRUCTIONS")
    
    echo -ne "Test $count nombres : "
    
    if [ "$CHECK_RESULT" == "OK" ]; then
        if [ $NB_COUPS -le $limit ]; then
             echo -e "${GREEN}OK${NC} ($NB_COUPS coups / limite $limit)"
        else
             echo -e "${YELLOW}OK MAIS TROP LONG${NC} ($NB_COUPS coups / limite $limit)"
        fi
    else
        echo -e "${RED}KO - LE TRI A ÉCHOUÉ${NC}"
      echo "Args utilisés: $ARGS"
    fi
}

# Test Identité (Déjà trié)
echo -ne "Test Déjà Trié (1 2 3 4 5) : "
RES=$($PUSH_SWAP 1 2 3 4 5)
if [ -z "$RES" ]; then
    echo -e "${GREEN}OK${NC} (Aucune instruction)"
else
    echo -e "${RED}FAIL${NC} (A renvoyé des instructions inutiles)"
fi

# Tests aléatoires
run_test 3 3
run_test 5 12
run_test 100 700
run_test 500 5500

echo ""
echo -e "${BLUE}Fin des tests.${NC}"