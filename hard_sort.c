/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:47:16 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/12 15:09:23 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_for_max(t_stack_node *stack)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = stack->value;
	nb2 = stack->next->value;
	nb3 = stack->next->next->value;
	if (nb1 > nb2 && nb1 > nb3)
		return (stack);
	if (nb2 > nb1 && nb2 > nb3)
		return (stack->next);
	if (nb3 > nb1 && nb3 > nb2)
		return (stack->next->next);
	return (stack);
}

void	three_sort(t_stack_node **stack)
{
	t_stack_node	*maxnod;

	maxnod = find_for_max(*stack);
	if (maxnod == *stack)
		ra(stack);
	else if (maxnod == (*stack)->next)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

int	get_min(t_stack_node *a)
{
	int	i;
	int	min_val;
	int	min_pos;

	i = 0;
	min_val = 2147483647;
	min_pos = 0;
	while (a)
	{
		if (a->index < min_val)
		{
			min_val = a->index;
			min_pos = i;
		}
		a = a->next;
		i++;
	}
	return (min_pos);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	int	min_pos;
	int	size;

	size = ft_lsttsize(*a);
	while (size > 3)
	{
		min_pos = get_min(*a);
		if (min_pos < size / 2)
		{
			while (min_pos-- > 0)
				ra(a);
		}
		else
		{
			while (min_pos++ < size)
				rra(a);
		}
		pb(a, b);
		size--;
	}
	three_sort(a);
	while ((*b))
		pa(a, b);
}

void	sorting(t_stack_node **a, t_stack_node **b)
{
	int	a_size;

	a_size = ft_lsttsize(*(a));
	indexation(*(a));
	if (a_size == 2)
		double_sort(a);
	else if (a_size == 3)
		three_sort(a);
	else if (a_size <= 5)
		sort_five(a, b);
	else
		butterfly(a, b, a_size);
}
