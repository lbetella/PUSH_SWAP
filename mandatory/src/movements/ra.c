/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:32:00 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/21 19:28:21 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_data *data)
{
	if (rotate(&data->stack_a))
	{
		write(1, "ra\n", 3);
		data->ra++;
		data->total_ops++;
	}
}
