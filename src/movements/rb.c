/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:41:18 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/21 19:28:23 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rb(t_data *data)
{
	if (rotate(&data->stack_b))
	{
		write(1, "rb\n", 3);
		data->rb++;
		data->total_ops++;
	}
}
