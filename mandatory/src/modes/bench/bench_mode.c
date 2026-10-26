/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 18:23:26 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/21 19:36:09 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	bench_mode(t_data *data)
{
	print_disorder(data->disorder);
	print_strategy(data->mode, data->disorder);
	print_total(data->total_ops);
	print_movements(data);
}
