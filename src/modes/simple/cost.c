/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   cost.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: lbetella <lbetella@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 13:00:20 by lbetella         #+#    #+#              */
/*   Updated: 2026/10/20 15:49:58 by lbetella        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static t_stack_node	*the_cheapest(t_stack_node *stack_b)
{
	t_stack_node	*start;
	t_stack_node	*current_cheapest;

	start = stack_b;
	current_cheapest = stack_b;
	while (1)
	{
		if (start->cost_b < current_cheapest->cost_b)
			current_cheapest = start;
		start = start->next;
		if (start == stack_b)
			break ;
	}
	return (current_cheapest);
}

static void	auxiliar(t_stack_node *start_stack_b, int cost_a, int cost_b)
{
	if (start_stack_b->upper == start_stack_b->target_node->upper)
	{
		if (cost_a > cost_b)
			start_stack_b->cost_b = cost_a;
		else
			start_stack_b->cost_b = cost_b;
	}
}

static void	total_cost(t_stack_node *stack_b, int len_a, int len_b)
{
	int				cost_b;
	int				cost_a;
	t_stack_node	*start_stack_b;

	start_stack_b = stack_b;
	while (1)
	{
		if (start_stack_b->upper == 1)
			cost_b = start_stack_b->pos;
		if (start_stack_b->upper == 0)
			cost_b = len_b - (start_stack_b->pos);
		if (start_stack_b->target_node->upper == 1)
			cost_a = start_stack_b->target_node->pos;
		if (start_stack_b->target_node->upper == 0)
			cost_a = len_a - (start_stack_b->target_node->pos);
		auxiliar(start_stack_b, cost_a, cost_b);
		if (start_stack_b->upper != start_stack_b->target_node->upper)
			start_stack_b->cost_b = (cost_a + cost_b);
		start_stack_b = start_stack_b->next;
		if (start_stack_b == stack_b)
			break ;
	}
}

t_stack_node	*cost(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				len_a;
	int				len_b;
	t_stack_node	*start_stack_b;
	t_stack_node	*cheapest;

	len_a = pos_upper_len(stack_a);
	len_b = pos_upper_len(stack_b);
	start_stack_b = *stack_b;
	total_cost(start_stack_b, len_a, len_b);
	cheapest = the_cheapest(start_stack_b);
	return (cheapest);
}
