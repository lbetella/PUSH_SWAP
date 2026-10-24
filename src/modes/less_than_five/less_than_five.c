/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:00:09 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/24 18:08:21 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	order_five_numbers(t_data *data)
{
	while (pos_upper_len(&data->stack_a) > 3)
	{
		if (data->stack_a->index == 1 || data->stack_a->index == 2)
			pb(data);
		else
			ra(data);
	}
	order_three_numbers(data);
	reverse_two_numbers_b(data);
	pa(data);
	pa(data);
}

static void	order_four_numbers(t_data *data)
{
	int	len_a;
	int	i;

	i = 0;
	len_a = pos_upper_len(&data->stack_a);
	while (i < len_a)
	{
		if (data->stack_a->index == 1)
		{
			pb(data);
			break ;
		}
		else
			ra(data);
		i++;
	}
	order_three_numbers(data);
	pa(data);
}

void	order_three_numbers(t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	top = data->stack_a->index;
	mid = data->stack_a->next->index;
	bot = data->stack_a->next->next->index;
	if (top > mid && mid < bot && top < bot)
		sa(data);
	else if (top > mid && mid > bot)
	{
		sa(data);
		rra(data);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(data);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(data);
		ra(data);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(data);
}

static void	order_two_numbers_a(t_data *data)
{
	int	top;
	int	bot;

	top = data->stack_a->index;
	bot = data->stack_a->next->index;
	if (top > bot)
		sa(data);
}

void	reverse_two_numbers_b(t_data *data)
{
	int	top;
	int	bot;

	top = data->stack_b->index;
	bot = data->stack_b->next->index;
	if (top < bot)
		sb(data);
}

void	less_than_five(t_data *data, int len_a)
{
	if (len_a == 2)
		order_two_numbers_a(data);
	else if (len_a == 3)
		order_three_numbers(data);
	else if (len_a == 4)
		order_four_numbers(data);
	else if (len_a == 5)
		order_five_numbers(data);
	if (data->bench == 1)
		bench_mode(data);
}