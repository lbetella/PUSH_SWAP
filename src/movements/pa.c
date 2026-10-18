/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:54:17 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/17 17:52:57 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (push(stack_b, stack_a))
		write(1, "pa\n", 3);
}
