/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:25:14 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/12 14:39:34 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_lst_last(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (0);
	node->value = n;
	node->next = NULL;
	node->prev = NULL;
	if (*stack == NULL)
		*stack = node;
	else
	{
		last = ft_lst_last(*stack);
		last->next = node;
		node->prev = last;
	}
	return (1);
}

void	ft_free_stack(t_stack_node **lst)
{
	t_stack_node	*current;
	t_stack_node	*crtnext;

	if (!lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		crtnext = current->next;
		free(current);
		current = crtnext;
	}
	*lst = NULL;
}

void	ft_free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	ft_error(t_stack_node **a, char **args)
{
	ft_free_stack(a);
	if (args != NULL)
		ft_free_args(args);
	write(2, "Error\n", 6);
	exit (1);
}
