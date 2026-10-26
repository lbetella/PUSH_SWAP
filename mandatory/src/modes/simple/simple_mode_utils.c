/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_mode_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 19:48:41 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/21 17:35:22 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	both_up(t_data *data, t_stack_node *to_move)
{
	while (to_move != data->stack_b && to_move->target_node != data->stack_a)
		rr(data);
	if (to_move == data->stack_b)
	{
		while (to_move->target_node != data->stack_a)
			ra(data);
	}
	else
	{
		while (to_move != data->stack_b)
			rb(data);
	}
	pa(data);
}

void	both_down(t_data *data, t_stack_node *to_move)
{
	while (to_move != data->stack_b && to_move->target_node != data->stack_a)
		rrr(data);
	if (to_move == data->stack_b)
	{
		while (to_move->target_node != data->stack_a)
			rra(data);
	}
	else
	{
		while (to_move != data->stack_b)
			rrb(data);
	}
	pa(data);
}

void	b_down(t_data *data, t_stack_node *to_move)
{
	while (to_move != data->stack_b && to_move->target_node != data->stack_a)
	{
		ra(data);
		rrb(data);
	}
	if (to_move == data->stack_b)
	{
		while (to_move->target_node != data->stack_a)
			ra(data);
	}
	else
	{
		while (to_move != data->stack_b)
			rrb(data);
	}
	pa(data);
}

void	a_down(t_data *data, t_stack_node *to_move)
{
	while (to_move != data->stack_b && to_move->target_node != data->stack_a)
	{
		rra(data);
		rb(data);
	}
	if (to_move == data->stack_b)
	{
		while (to_move->target_node != data->stack_a)
			rra(data);
	}
	else
	{
		while (to_move != data->stack_b)
			rb(data);
	}
	pa(data);
}
