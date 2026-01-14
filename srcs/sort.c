/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:47:16 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/13 14:11:27 by amurtas          ###   ########.fr       */
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
			if (a->value > curr->value)
				a->index++;
			curr = curr->next;
		}
		a = a->next;
		curr = head;
	}
	a = head;
}

int	find_max(t_stack_node **b)
{
	int				current_pos;
	int				max_val;
	int				max_pos;
	t_stack_node	*current;

	current_pos = 0;
	max_val = -2147483648;
	max_pos = 0;
	current = (*b);
	while (current)
	{
		if (current->index > max_val)
		{
			max_val = current->index;
			max_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (max_pos);
}

void	butterfly_a(t_stack_node **a, t_stack_node **b, int i, int n)
{
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= i + n)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index > i + n)
			ra(a);
	}
}

void	butterfly(t_stack_node **a, t_stack_node **b, int count)
{
	int	i;
	int	n;
	int	targ_ind;

	i = 0;
	if (count <= 100)
		n = 15;
	else
		n = 30;
	butterfly_a(a, b, i, n);
	while (*b)
	{
		targ_ind = find_max(b);
		if (targ_ind == 0)
			pa(a, b);
		else
		{
			if (targ_ind < ft_lsttsize((*b)) / 2)
				rb(b);
			else
				rrb(b);
		}
	}
}
