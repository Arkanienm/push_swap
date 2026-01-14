/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:47:16 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/13 14:06:48 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lsttsize(t_stack_node *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	check_args(int argc)
{
	if (argc < 2)
	{
		ft_error(NULL, NULL);
		return (0);
	}
	return (1);
}

void	double_sort(t_stack_node **a)
{
	t_stack_node	*node;

	node = *a;
	if (node->value > node->next->value)
		sa(a);
}

void	init_stack_a(t_stack_node **a, char **args)
{
	long	nb;
	int		i;

	i = 0;
	nb = 0;
	if (!args[i])
	{
		ft_error(a, args);
		exit(0);
	}
	while (args[i])
	{
		if (!check_syntax(args[i]))
			ft_error(a, args);
		nb = ft_atol(args[i]);
		if (nb < -2147483648 || nb > 2147483647)
			ft_error(a, args);
		if (check_duplicate(*(a), (int)nb))
			ft_error(a, args);
		if (!ft_append_node(a, (int)nb))
			ft_error(a, args);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;
	int				i;

	if (!check_args(argc))
		return (0);
	i = 1;
	a = NULL;
	b = NULL;
	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		init_stack_a(&a, args);
		i++;
		ft_free_args(args);
	}
	if (ft_is_sorted(&a))
	{
		ft_free_stack(&a);
		return (0);
	}
	sorting(&a, &b);
	ft_free_stack(&a);
	return (0);
}
