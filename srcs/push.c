/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:44:47 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/12 13:52:07 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	ft_printf("pb\n");
}
