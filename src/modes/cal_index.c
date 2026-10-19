/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:44:24 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/19 19:00:39 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	cal_index(t_stack_node *stack)
{
	int	i;
	int	first;
	t_stack_node	*start;
	t_stack_node	*again;
	
	first = 1;
	again = stack;
	while (again != stack || first == 1)
	{
		i = 1;
		start = again->next;
		while (start != again)
		{	
			if (start->value < again->value)
				i++;
			start = start->next;
		}
		again->index = i;
		again = again->next;
		first = 0;
	}
}