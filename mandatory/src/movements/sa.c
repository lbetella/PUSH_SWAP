/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:36:28 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/21 19:28:36 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_data *data)
{
	if (swap(&data->stack_a))
	{
		write(1, "sa\n", 3);
		data->sa++;
		data->total_ops++;
	}
}
