/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:47:16 by amurtas           #+#    #+#             */
/*   Updated: 2026/01/05 18:03:00 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *three_sort(t_stack_node *stack)
{
	int nb1;
	int nb2;
	int nb3;
	
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

int	main(int argc, char **argv)
{
	char **args;


	
	if (argc < 2)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	if (argc > 2)
		*args = argv[1];
	if (check_syntax && !check_duplicate())
	{
		/* code */
	}
}
