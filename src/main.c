/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:37:42 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/24 18:38:41 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		len_a;

	start(&data);
	if (argc < 2)
		return (0);
	if (!parser(argc, argv, &data) || !data.stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		parser_free(NULL, data.stack_a);
		return (1);
	}
	cal_index(data.stack_a);
	data.disorder = cal_index_error(&data);
	if (data.disorder == 0)
		return (parser_free(NULL, data.stack_a), 0);
	len_a = pos_upper_len(&data.stack_a);
	if (len_a <= 5)
		less_than_five(&data, len_a);
	else
		mode_selector(&data);
	parser_free(NULL, data.stack_a);
	parser_free(NULL, data.stack_b);
	return (0);
}
