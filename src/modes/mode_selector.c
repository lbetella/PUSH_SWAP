/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_selector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 18:03:32 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/19 19:03:54 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	mode_selector(t_data *data)
{
	if (data->mode == 1)
	{
		ft_printf("modo cogio");
		simple_mode(data);
	}
	else if (data->mode == 2)
		medium_mode(data);
	else if (data->mode == 3)
		complex_mode(data);
	else if (data->mode == 4 || data->mode == 0)
		adaptive_mode(data);
	if (data->bench == 1)
		bench_mode(data);
}

// void	mode_selector(t_data *data)
// {
// 	(void)data;
// }
