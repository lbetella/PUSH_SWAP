/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_mode_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbetella <lbetella@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 19:48:41 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/20 19:48:52 by lbetella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	both_up(t_data *data, t_stack_node *to_move)
{
	while (to_move != data->stack_b && to_move->target_node != data->stack_a)
		rr(&data->stack_a, &data->stack_b);
	if (to_move == data->stack_b)
	{
		while (to_move->target_node != data->stack_a)
			ra(&data->stack_a);
	}
	else
	{
		while (to_move != data->stack_b)
			rb(&data->stack_b);
	}
	pa(&data->stack_a, &data->stack_b);
}

void	both_down(t_data *data, t_stack_node *to_move)
{
	while (to_move != data->stack_b && to_move->target_node != data->stack_a)
		rrr(&data->stack_a, &data->stack_b);
	if (to_move == data->stack_b)
	{
		while (to_move->target_node != data->stack_a)
			rra(&data->stack_a);
	}
	else
	{
		while (to_move != data->stack_b)
			rrb(&data->stack_b);
	}
	pa(&data->stack_a, &data->stack_b);
}

void	b_down(t_data *data, t_stack_node *to_move)
{
	while (to_move != data->stack_b && to_move->target_node != data->stack_a)
	{
		ra(&data->stack_a);
		rrb(&data->stack_b);
	}
	if (to_move == data->stack_b)
	{
		while (to_move->target_node != data->stack_a)
			ra(&data->stack_a);
	}
	else
	{
		while (to_move != data->stack_b)
			rrb(&data->stack_b);
	}
	pa(&data->stack_a, &data->stack_b);
}

void	a_down(t_data *data, t_stack_node *to_move)
{
	while (to_move != data->stack_b && to_move->target_node != data->stack_a)
	{
		rra(&data->stack_a);
		rb(&data->stack_b);
	}
	if (to_move == data->stack_b)
	{
		while (to_move->target_node != data->stack_a)
			rra(&data->stack_a);
	}
	else
	{
		while (to_move != data->stack_b)
			rb(&data->stack_b);
	}
	pa(&data->stack_a, &data->stack_b);
}
