/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:43:04 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/21 19:28:40 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ss(t_data *data)
{
	if (!data->stack_a || !data->stack_b || !data->stack_a || !data->stack_b
		|| data->stack_a->next == data->stack_a
		|| data->stack_b->next == data->stack_b)
		return ;
	else
	{
		swap(&data->stack_a);
		swap(&data->stack_b);
		write(1, "ss\n", 3);
		data->ss++;
		data->total_ops++;
	}
}
