/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:37:42 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/18 19:47:46 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.mode = 0;
	data.bench = 0;
	data.stack_a = NULL;
	data.stack_b = NULL;
	if (argc < 2 || !parser(argc, argv, &data) || !data.stack_a)
	{
		ft_printf("Error\n");
		return (1);
	}
	else
	{
		ft_printf("Modo: %i\nBench: %i\n", data.mode, data.bench);
		mode_selector(&data);
	}
	return (0);
}
