/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_upper_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:11:49 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/19 13:22:36 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_upper_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbetella <lbetella@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:10:40 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/19 13:11:08 by lbetella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	pos_upper_len(t_stack_node **stack)
{
	int				count_len;
	t_stack_node	*temp;

	if (!stack || !*stack)
		return (0);
	count_len = 1;
	temp = *stack;
	while (temp->next != *stack)
	{
		temp->pos = count_len - 1;
		count_len++;
		temp = temp->next;
	}
	temp->pos = count_len - 1;
	temp = *stack;
	while (temp->next != *stack)
	{
		temp->upper = (temp->pos <= count_len / 2);
		temp = temp->next;
	}
	temp->upper = (temp->pos <= count_len / 2);
	return (count_len);
}
