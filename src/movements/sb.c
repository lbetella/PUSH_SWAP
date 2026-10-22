/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:36:53 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/21 19:28:38 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sb(t_data *data)
{
	if (swap(&data->stack_b))
	{
		write(1, "sb\n", 3);
		data->sb++;
		data->total_ops++;
	}
}
