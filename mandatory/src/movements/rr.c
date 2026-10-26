/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:44:19 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/21 19:28:26 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rr(t_data *data)
{
	if (!data->stack_a || !data->stack_b || !data->stack_a || !data->stack_b
		|| data->stack_a->next == data->stack_a
		|| data->stack_b->next == data->stack_b)
		return ;
	else
	{
		rotate(&data->stack_a);
		rotate(&data->stack_b);
		write(1, "rr\n", 3);
		data->rr++;
		data->total_ops++;
	}
}
