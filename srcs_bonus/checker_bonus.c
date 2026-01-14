/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:10:56 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/14 18:03:52 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	checker(char *line, t_stack_node **a, t_stack_node **b)
{
	if (ft_strcmp(line, "pa\n"))
		pa(a, b);
	else if (ft_strcmp(line, "pb\n"))
		pb(a, b);
	else if (ft_strcmp(line, "sa\n"))
		sa(a);
	else if (ft_strcmp(line, "sb\n"))
		sb(b);
	else if (ft_strcmp(line, "ss\n"))
		ss(a, b);
	else if (ft_strcmp(line, "ra\n"))
		ra(a);
	else if (ft_strcmp(line, "rb\n"))
		rb(b);
	else if (ft_strcmp(line, "rr\n"))
		rr(a, b);
	else if (ft_strcmp(line, "rra\n"))
		rra(a);
	else if (ft_strcmp(line, "rrb\n"))
		rrb(b);
	else if (ft_strcmp(line, "rrr\n"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	check_validation(t_stack_node **a, t_stack_node **b)
{
	char	*line;

	line = get_next_line (0);
	while (line != NULL)
	{
		if (!checker(line, a, b))
		{
			get_next_line(-1);
			free(line);
			if (b && (*b))
				ft_free_stack(b);
			ft_error(a, NULL);
		}
		if (line)
			free(line);
		line = get_next_line(0);
	}
	if (!ft_is_sorted(a))
		ft_printf("KO");
	else
		ft_printf("OK");
	return (1);
}
