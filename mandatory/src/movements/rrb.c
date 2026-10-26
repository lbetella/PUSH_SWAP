/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:57:28 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/21 19:28:31 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rrb(t_data *data)
{
	if (rotatereverse(&data->stack_b))
	{
		write(1, "rrb\n", 4);
		data->rrb++;
		data->total_ops++;
	}
}
