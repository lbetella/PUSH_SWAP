/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_mode_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:51:15 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/22 13:52:35 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	pivot(t_data *data, int len_a)
{
	if (len_a <= 300)
	{
		data->p[1] = len_a / 6;
		data->p[2] = (2 * len_a) / 6;
		data->p[3] = (3 * len_a) / 6;
		data->p[4] = (4 * len_a) / 6;
		data->p[5] = (5 * len_a) / 6;
		data->p[6] = 0;
	}
	else
	{
		data->p[1] = len_a / 11;
		data->p[2] = (2 * len_a) / 11;
		data->p[3] = (3 * len_a) / 11;
		data->p[4] = (4 * len_a) / 11;
		data->p[5] = (5 * len_a) / 11;
		data->p[6] = (6 * len_a) / 11;
		data->p[7] = (7 * len_a) / 11;
		data->p[8] = (8 * len_a) / 11;
		data->p[9] = (9 * len_a) / 11;
		data->p[10] = (10 * len_a) / 11;
	}
}

void	move_to_b(t_data *data, t_stack_node *choosen)
{
	if (choosen->upper == 1)
	{
		while (choosen != data->stack_b)
			rb(data);
	}
	else
	{
		while (choosen != data->stack_b)
			rrb(data);
	}
	pa(data);
}

void	b_to_a_complex(t_data *data)
{
	t_stack_node	*choosen;
	t_stack_node	*temp;

	choosen = data->stack_b;
	temp = data->stack_b;
	while (data->stack_b)
	{
		pos_upper_len(&data->stack_b);
		if (choosen->index < temp->index)
			choosen = temp;
		temp = temp->next;
		if (temp == data->stack_b)
			break ;
	}
	move_to_b(data, choosen);
}
