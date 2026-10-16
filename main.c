/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:37:42 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/16 21:38:24 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_flags(int argc, char **argv, int *mode, int *bench)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i] && argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (ft_strncmp(argv[i], "--simple", 9) == 0 && *mode == 0)
				*mode = 1;
			else if (ft_strncmp(argv[i], "--medium", 9) == 0 && *mode == 0)
				*mode = 2;
			else if (ft_strncmp(argv[i], "--complex", 10) == 0 && *mode == 0)
				*mode = 3;
			else if (ft_strncmp(argv[i], "--adaptive", 11) == 0 && *mode == 0)
				*mode = 4;
			else if (ft_strncmp(argv[i], "--bench", 8) == 0 && *bench == 0)
				*bench = 1;
			else
				return (0);
		}
	}
	return (*mode);
}

int	main(int argc, char **argv)
{
	int	mode;
	int	bench;


	mode = 0;
	bench = 0;
	if (check_flags(argc, argv, &mode, &bench) == 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_printf("Modo: %i\nBench: %i\n", mode, bench);
	return (0);
}
