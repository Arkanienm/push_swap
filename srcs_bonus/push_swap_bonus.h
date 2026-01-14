/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:47:50 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/14 17:29:14 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../srcs/ft_printf/ft_printf.h"
# include "../srcs/Libft/libft.h"
# include "get_next_line.h"
# include <stdlib.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void			init_stack_a(t_stack_node **a, char **argv);
long			ft_atol(const char	*str);
int				check_syntax(char *str);
int				check_duplicate(t_stack_node *a, int n);
void			ft_error(t_stack_node **a, char **args);
void			ft_free_stack(t_stack_node **lst);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			three_sort(t_stack_node **stack);
t_stack_node	*ft_lst_last(t_stack_node *lst);
void			ft_free_args(char **args);
int				ft_lsttsize(t_stack_node *lst);
void			butterfly(t_stack_node **a, t_stack_node **b, int count);
void			indexation(t_stack_node *a);
void			sorting(t_stack_node **a, t_stack_node **b);
void			double_sort(t_stack_node **a);
int				ft_append_node(t_stack_node **stack, int n);
int				ft_is_sorted(t_stack_node **a);
int				checker(char *line, t_stack_node **a, t_stack_node **b);
int				check_validation(t_stack_node **a, t_stack_node **b);
int				ft_strcmp(char *s1, char *s2);

#endif