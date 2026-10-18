/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:05:00 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/17 17:52:55 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (push(stack_a, stack_b))
		write(1, "pb\n", 3);
}
