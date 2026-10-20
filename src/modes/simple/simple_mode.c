/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple_mode.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: lbetella <lbetella@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/18 18:14:05 by lbetella         #+#    #+#              */
/*   Updated: 2026/10/20 19:45:03 by lbetella        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	a_to_b(t_data *data)
{
	int	len_a;
	int	counter;

	len_a = pos_upper_len(&data->stack_a);
	counter = 0;
	while (counter <= len_a)
	{
		if (data->stack_a->index <= ((len_a + 1) / 2))
			pb(&data->stack_a, &data->stack_b);
		else
			ra(&data->stack_a);
		counter++;
	}
	len_a = pos_upper_len(&data->stack_a);
	while (len_a > 3)
	{
		pb(&data->stack_a, &data->stack_b);
		len_a--;
	}
}

static void	mode_simple(t_data *data, t_stack_node *to_move)
{
	while (data->stack_b != NULL)
	{
		look_for_target(data->stack_a, data->stack_b);
		to_move = cost(&data->stack_a, &data->stack_b);
		if (to_move->upper == 1 && to_move->target_node->upper == 1)
			both_up(data, to_move);
		else if (to_move->upper == 0 && to_move->target_node->upper == 0)
			both_down(data, to_move);
		else if (to_move->upper == 0 && to_move->target_node->upper == 1)
			b_down(data, to_move);
		else if (to_move->upper == 1 && to_move->target_node->upper == 0)
			a_down(data, to_move);
	}
}

void	simple_mode(t_data *data)
{
	t_stack_node	*to_move;
	t_stack_node	*to_find;

	cal_index(data->stack_a);
	a_to_b(data);
	order_three_numbers(data);
	to_move = NULL;
	mode_simple(data, to_move);
	pos_upper_len(&data->stack_a);
	to_find = data->stack_a;
	while (1)
	{
		if (to_find->index == 1)
			break ;
		to_find = to_find->next;
	}
	while (to_find != data->stack_a)
	{
		if (to_find->upper == 1)
			ra(&data->stack_a);
		else
			rra(&data->stack_a);
	}
}
