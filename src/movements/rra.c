/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:56:34 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/21 19:28:29 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_data *data)
{
	if (rotatereverse(&data->stack_a))
	{
		write(1, "rra\n", 4);
		data->rra++;
		data->total_ops++;
	}
}
