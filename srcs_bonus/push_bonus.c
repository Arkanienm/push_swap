/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:44:47 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/14 16:50:57 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*nsrc;
	t_stack_node	*ndest;

	if (!src || !*src)
		return ;
	nsrc = *src;
	ndest = *dest;
	if (nsrc->next)
		nsrc->next->prev = NULL;
	*src = nsrc->next;
	if (ndest)
	{
		nsrc->next = ndest;
		nsrc->prev = ndest->prev;
		ndest->prev = nsrc;
	}
	else
	{
		nsrc->prev = NULL;
		nsrc->next = NULL;
	}
	*dest = nsrc;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
}
