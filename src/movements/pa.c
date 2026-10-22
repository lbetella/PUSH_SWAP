/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:54:17 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/21 19:28:13 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_data *data)
{
	if (push(&data->stack_b, &data->stack_a))
	{
		write(1, "pa\n", 3);
		data->pa++;
		data->total_ops++;
	}
}
