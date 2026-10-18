/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:44:19 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/17 17:52:46 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b
		|| (*stack_a)->next == *stack_a || (*stack_b)->next == *stack_b)
		return ;
	else
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
}
