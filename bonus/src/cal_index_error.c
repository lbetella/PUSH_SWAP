/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_index_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 13:23:13 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/26 17:40:02 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

double	cal_index_error(t_data *data)
{
	t_stack_node	*current;
	t_stack_node	*check;

	current = data->stack_a;
	while (current->next != data->stack_a)
	{
		check = current->next;
		while (check != data->stack_a)
		{
			if (current->value > check->value)
				return (-1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}
