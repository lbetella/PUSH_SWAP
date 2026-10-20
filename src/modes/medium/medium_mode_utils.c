/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium_mode_utils.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: lbetella <lbetella@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 15:53:55 by lbetella         #+#    #+#              */
/*   Updated: 2026/10/20 19:36:20 by lbetella        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	else if (size <= 500)
		return (35);
	else
		return (60);
}

int	stack_len(t_stack_node *stack_a)
{
	int				len;
	t_stack_node	*current;

	if (!stack_a)
		return (0);
	len = 1;
	current = stack_a->next;
	while (current != stack_a)
	{
		current = current->next;
		len++;
	}
	return (len);
}

int	get_max_pos(t_stack_node *stack_b)
{
	t_stack_node	*current;
	int				max_index;
	int				max_pos;
	int				pos;

	current = stack_b;
	max_index = current->index;
	max_pos = 0;
	pos = 0;
	while (1)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
		if (current == stack_b)
			break ;
	}
	return (max_pos);
}
