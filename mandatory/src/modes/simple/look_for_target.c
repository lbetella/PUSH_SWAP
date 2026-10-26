/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   look_for_target.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: lbetella <lbetella@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 20:03:49 by lbetella         #+#    #+#              */
/*   Updated: 2026/10/20 19:35:55 by lbetella        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	set_target(t_stack_node *stack_a, t_stack_node *stack_b, int bt)
{
	t_stack_node	*start_stack_a;
	t_stack_node	*target_node;
	t_stack_node	*minimum;

	start_stack_a = stack_a;
	minimum = stack_a;
	target_node = NULL;
	while (1)
	{
		if (stack_b->index < start_stack_a->index
			&& bt > start_stack_a->index)
		{
			bt = start_stack_a->index;
			target_node = start_stack_a;
		}
		if (minimum->index > start_stack_a->index)
			minimum = start_stack_a;
		start_stack_a = start_stack_a->next;
		if (start_stack_a == stack_a)
			break ;
	}
	if (bt == INT_MAX)
		stack_b->target_node = minimum;
	else
		stack_b->target_node = target_node;
}

void	look_for_target(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*start_stack_b;

	start_stack_b = stack_b;
	while (1)
	{
		set_target(stack_a, start_stack_b, INT_MAX);
		start_stack_b = start_stack_b->next;
		if (start_stack_b == stack_b)
			break ;
	}
}
