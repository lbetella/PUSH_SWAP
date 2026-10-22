/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 17:45:45 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/22 13:14:16 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	start(t_data *data)
{
	data->mode = 0;
	data->bench = 0;
	data->disorder = 0;
	data->total_ops = 0;
	data->p[0] = 0;
	data->p[1] = 0;
	data->p[2] = 0;
	data->p[3] = 0;
	data->p[4] = 0;
	data->p[5] = 0;
	data->p[6] = 0;
	data->p[7] = 0;
	data->p[8] = 0;
	data->p[9] = 0;
	data->p[10] = 0;
	data->pa = 0;
	data->pb = 0;
	data->ra = 0;
	data->rra = 0;
	data->rb = 0;
	data->rrb = 0;
	data->rr = 0;
	data->rrr = 0;
	data->sa = 0;
	data->sb = 0;
	data->ss = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
}
