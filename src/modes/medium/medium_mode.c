/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 18:14:14 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/20 15:57:52 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	order_three_numbers(t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	top = data->stack_a->index;
	mid = data->stack_a->next->index;
	bot = data->stack_a->next->next->index;
	if (top > mid && mid < bot && top < bot)
		sa(&data->stack_a);
	else if (top > mid && mid > bot)
	{
		sa(&data->stack_a);
		rra(&data->stack_a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(&data->stack_a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(&data->stack_a);
		ra(&data->stack_a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(&data->stack_a);
}

void	send_to_b(t_data *data, int min, int chunk_size)
{
	int	total_size;

	total_size = stack_len(data->stack_a);
	while (stack_len(data->stack_a) > 3)
	{
		if (data->stack_a->index > total_size - 3)
			ra(&data->stack_a);
		else if (data->stack_a->index <= min)
		{
			pb(&data->stack_a, &data->stack_b);
			rb(&data->stack_b);
			min++;
		}
		else if (data->stack_a->index <= min + chunk_size)
		{
			pb(&data->stack_a, &data->stack_b);
			min++;
		}
		else
			ra(&data->stack_a);
	}
}

void	send_to_a(t_data *data)
{
	int	len;
	int	pos;

	while (data->stack_b != NULL)
	{
		len = stack_len(data->stack_b);
		pos = get_max_pos(data->stack_b);
		if (pos <= len / 2)
		{
			while (pos > 0)
			{
				rb(&data->stack_b);
				pos--;
			}
		}
		else
		{
			pos = len - pos + 1;
			while (--pos > 0)
				rrb(&data->stack_b);
		}
		pa(&data->stack_a, &data->stack_b);
	}
}

void	medium_mode(t_data *data)
{
	int	chunk_size;
	int	min;

	cal_index(data->stack_a);
	chunk_size = get_chunk_size(stack_len(data->stack_a));
	min = 1;
	send_to_b(data, min, chunk_size);
	order_three_numbers(data);
	send_to_a(data);
}
