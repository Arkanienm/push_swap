NAME        = push_swap
NAME_BONUS  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

SRCS        = srcs/main.c srcs/all_check.c srcs/ft_atol.c srcs/ft_stack_utils.c \
			  srcs/swap.c srcs/push.c srcs/rotate.c srcs/reverse_rotate.c srcs/sort.c \
			  srcs/hard_sort.c srcs/is_sorted.c

BONUS_SRCS  = srcs_bonus/main_bonus.c srcs/all_check.c srcs/ft_atol.c srcs/ft_stack_utils.c \
			  srcs_bonus/swap_bonus.c srcs_bonus/push_bonus.c srcs_bonus/rotate_bonus.c \
			  srcs_bonus/reverse_rotate_bonus.c srcs/sort.c srcs/hard_sort.c srcs/is_sorted.c \
			  srcs_bonus/checker_bonus.c srcs_bonus/get_next_line.c srcs_bonus/get_next_line_utils.c \
			  srcs_bonus/ft_strcmp.c 

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)
FT_PRINTF       = ./srcs/ft_printf/libftprintf.a
LIBFT       	= ./srcs/Libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./srcs/ft_printf
	make -C ./srcs/Libft
	$(CC) $(OBJS) $(FT_PRINTF) $(LIBFT) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	make -C ./srcs/ft_printf
	make -C ./srcs/Libft
	$(CC) $(BONUS_OBJS) $(FT_PRINTF) $(LIBFT) -o $(NAME_BONUS)
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C ./srcs/ft_printf
	make clean -C ./srcs/Libft

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C ./srcs/ft_printf
	make fclean -C ./srcs/Libft

re: fclean all

.PHONY: all clean fclean re bonus
