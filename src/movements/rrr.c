/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:57:49 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/21 19:28:33 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rrr(t_data *data)
{
	if (!data->stack_a || !data->stack_b || !data->stack_a || !data->stack_b
		|| data->stack_a->next == data->stack_a
		|| data->stack_b->next == data->stack_b)
		return ;
	else
	{
		rotatereverse(&data->stack_a);
		rotatereverse(&data->stack_b);
		write(1, "rrr\n", 4);
		data->rrr++;
		data->total_ops++;
	}
}
