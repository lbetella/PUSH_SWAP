/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_five_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 18:39:13 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/24 18:40:57 by guilfran         ###   ########.fr       */
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

void	reverse_two_numbers_b(t_data *data)
{
	int	top;
	int	bot;

	top = data->stack_b->index;
	bot = data->stack_b->next->index;
	if (top < bot)
		sb(data);
}
