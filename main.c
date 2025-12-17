/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:47:16 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/17 13:34:56 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_verif(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		ft_split(argv[1], ' ');
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (args_verif(argc, argv) == 0)
		return (0);
}
