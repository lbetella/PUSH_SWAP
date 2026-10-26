/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:05:00 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/21 19:28:19 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb(t_data *data)
{
	if (push(&data->stack_a, &data->stack_b))
	{
		write(1, "pb\n", 3);
		data->pb++;
		data->total_ops++;
	}
}
