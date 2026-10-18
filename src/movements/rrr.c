/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:57:49 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/17 17:52:41 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b
		|| (*stack_a)->next == *stack_a || (*stack_b)->next == *stack_b)
		return ;
	else
	{
		rotatereverse(stack_a);
		rotatereverse(stack_b);
		write(1, "rrr\n", 4);
	}
}
