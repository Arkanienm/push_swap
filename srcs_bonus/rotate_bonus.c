/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:44:47 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/14 15:55:12 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	node = *stack;
	last = ft_lst_last(node);
	*stack = node->next;
	(*stack)->prev = NULL;
	node->next = NULL;
	node->prev = last;
	last->next = node;
}

void	ra(t_stack_node **a)
{
	rotate(a);
}

void	rb(t_stack_node **b)
{
	rotate(b);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
}
