/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:43:04 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/17 17:52:36 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b
		|| (*stack_a)->next == *stack_a || (*stack_b)->next == *stack_b)
		return ;
	else
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
	}
}
