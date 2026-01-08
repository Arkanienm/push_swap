/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:47:16 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/08 15:02:43 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack_node *lst)
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

int	check_args(t_stack_node argc, )
{
	if (argc < 2)
	{
		ft_error(&a, NULL);
		return(0);
	}
	
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;
	int				i;

	if (argc < 2)
	{
		ft_error(&a, NULL);
		return(0);
	}
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
	if (argc == 4)
		three_sort(&a);
	ft_free_stack(&a);
	return (0);
}
