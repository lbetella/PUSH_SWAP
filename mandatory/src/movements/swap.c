/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:35:32 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/17 17:52:35 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;
	t_stack_node	*tail;

	if (!head || !*head || (*head)->next == *head)
		return (0);
	first = *head;
	second = first->next;
	third = second->next;
	tail = first->prev;
	if ((*head)->next->next == *head)
		*head = (*head)->next;
	else
	{
		second->next = first;
		first->prev = second;
		tail->next = second;
		second->prev = tail;
		first->next = third;
		third->prev = first;
		*head = second;
	}
	return (1);
}
