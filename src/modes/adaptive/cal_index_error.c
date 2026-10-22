/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_index_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 13:23:13 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/21 19:40:31 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

double	cal_index_error(t_data *data)
{
	t_stack_node	*current;
	t_stack_node	*check;
	double			total;
	double			error;

	total = 0;
	error = 0;
	current = data->stack_a;
	while (current->next != data->stack_a)
	{
		check = current->next;
		while (check != data->stack_a)
		{
			if (current->index > check->index)
				error++;
			total++;
			check = check->next;
		}
		current = current->next;
	}
	if (total == 0)
		return (0.0);
	return (error / total);
}
