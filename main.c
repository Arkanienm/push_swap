/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:47:16 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/08 12:31:51 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	if (argc < 2)
	{
		ft_error(&a);
		return(0);
	}
	a = NULL;
	b = NULL;
	init_stack_a(&a, argv + 1);
	if (argc == 4)
		three_sort(&a);
	
	ft_free_stack(&a);
	return (0);
}
