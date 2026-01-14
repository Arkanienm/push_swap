/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:44:47 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/12 13:53:03 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack_node **stack)
{
	t_stack_node	*node;
	t_stack_node	*last;
	t_stack_node	*belast;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	node = *stack;
	last = ft_lst_last(node);
	belast = last->prev;
	belast->next = NULL;
	last->next = *stack;
	node->prev = last;
	last->prev = NULL;
	*stack = last;
}

void	rra(t_stack_node **a)
{
	r_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	r_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	r_rotate(a);
	r_rotate(b);
	ft_printf("rrr\n");
}
