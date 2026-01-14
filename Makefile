NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

SRCS        = main.c all_check.c ft_atol.c ft_stack_utils.c swap.c \
			  push.c rotate.c reverse_rotate.c sort.c hard_sort.c is_sorted.c

OBJS        = $(SRCS:.c=.o)

FT_PRINTF       = ./ft_printf/libftprintf.a
LIBFT       	= ./Libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./ft_printf
	make -C ./Libft
	$(CC) $(OBJS) $(FT_PRINTF) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C ./ft_printf
	make clean -C ./Libft

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C ./ft_printf
	make fclean -C ./Libft

re: fclean all

.PHONY: all clean fclean re bonus
