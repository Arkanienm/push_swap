/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:47:16 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/09 13:40:03 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexation(t_stack_node *a)
{
	t_stack_node	*head;
	t_stack_node	*curr;

	head = a;
	curr = a;
	while (a)
	{
		a->index = 0;
		while (curr)
		{
			if(a->value > curr->value)
				a->index++;
			curr = curr->next;
		}
		a = a->next;
		curr = head;
	}
	a = head;
}

void	butterfly(t_stack_node **a, t_stack_node **b, int count)
{
	int	i;
	int	n;

	i = 0;
	if (count <= 100)
		n = 15;
	else
		n = 30;
	while (*a)
	{
		if ((*a)->index <= i + n)
		{
			pb(a, b);
			i++;
		}
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		if ((*a)->index > i + n)
			ra(a);
	}
	
}

t_stack_node *three_sort_max(t_stack_node *stack)
{
	int	nb1;
	int	nb2;
	int	nb3;
	
	nb1 = stack->value;
	nb2 = stack->next->value;
	nb3 = stack->next->next->value;

	if (nb1 > nb2 && nb1 > nb3)
		return(stack);
	if (nb2 > nb1 && nb2 >nb3)
		return(stack->next);
	if (nb3 > nb1 && nb3 > nb2)
		return(stack->next->next);
	return (stack);
}

void three_sort(t_stack_node **stack)
{
	t_stack_node	*maxnod;
	
	maxnod = three_sort_max(*stack);
	if (maxnod == *stack)
		ra(stack);
	else if (maxnod == (*stack)->next)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}
