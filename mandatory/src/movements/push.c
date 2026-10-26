/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:59:16 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/17 17:52:54 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	pushtostack(t_stack_node **stack, t_stack_node *extract)
{
	t_stack_node	*head;
	t_stack_node	*tail;

	if (!stack || !extract)
		return ;
	if (!*stack)
	{
		extract->next = extract;
		extract->prev = extract;
		*stack = extract;
	}
	else
	{
		head = *stack;
		tail = head->prev;
		extract->next = head;
		extract->prev = tail;
		tail->next = extract;
		head->prev = extract;
		*stack = extract;
	}
}

int	push(t_stack_node **stack1, t_stack_node **stack2)
{
	t_stack_node	*extract;
	t_stack_node	*second;
	t_stack_node	*tail;

	if (!stack1 || !*stack1)
		return (0);
	extract = *stack1;
	second = extract->next;
	tail = extract->prev;
	if (second == extract)
		*stack1 = NULL;
	else
	{
		tail->next = second;
		second->prev = tail;
		*stack1 = extract->next;
	}
	pushtostack(stack2, extract);
	return (1);
}
