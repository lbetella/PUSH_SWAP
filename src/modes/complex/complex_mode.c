/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 18:14:16 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/22 18:05:52 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	a_to_b_complex(t_data *data, int len_a)
{
	while (pos_upper_len(&data->stack_a) > 3)
	{
		if (data->stack_a->index > len_a - 3)
			ra(data);
		else
			pb(data);
	}
}

static void	partition_500(t_data *data, int counter, int i, int j)
{
	counter = 0;
	while (j <= 10)
	{
		while (counter < data->p[j])
		{
			if (data->stack_a->index <= data->p[i])
			{
				pb(data);
				if (data->stack_a->index > data->p[j])
					rr(data);
				else
					rb(data);
			}
			else if (data->stack_a->index <= data->p[j])
				pb(data);
			else
			{
				ra(data);
				counter--;
			}
			counter++;
		}
		i += 2;
		j += 2;
	}
}

static void	partition_300(t_data *data, int counter, int i, int j)
{
	counter = 0;
	while (j <= 6)
	{
		while (counter < data->p[j])
		{
			if (data->stack_a->index <= data->p[i])
			{
				pb(data);
				if (data->stack_a->index > data->p[j])
					rr(data);
				else
					rb(data);
			}
			else if (data->stack_a->index <= data->p[j])
				pb(data);
			else
			{
				ra(data);
				counter--;
			}
			counter++;
		}
		i += 2;
		j += 2;
	}
}

static void	partition_100(t_data *data, int len_a)
{
	int	p1;
	int	p2;

	p1 = len_a / 3;
	p2 = (2 * len_a) / 3;
	while (pos_upper_len(&data->stack_a) > len_a - p2)
	{
		if (data->stack_a->index <= p1)
		{
			pb(data);
			if (data->stack_a->index > p2)
				rr(data);
			else
				rb(data);
		}
		else if (data->stack_a->index <= p2)
			pb(data);
		else
			ra(data);
	}
}

void	complex_mode(t_data *data)
{
	int	len_a;
	int	counter;
	int	i;
	int	j;

	i = 1;
	j = 2;
	counter = 0;
	len_a = pos_upper_len(&data->stack_a);
	if (len_a <= 100)
		partition_100(data, len_a);
	else if (len_a <= 300)
	{
		pivot(data, len_a);
		partition_300(data, counter, i, j);
	}
	else
	{
		pivot(data, len_a);
		partition_500(data, counter, i, j);
	}
	a_to_b_complex(data, len_a);
	order_three_numbers(data);
	while (data->stack_b)
		b_to_a_complex(data);
}
