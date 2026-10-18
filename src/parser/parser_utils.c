/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:44:02 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/18 18:28:41 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	node_to_stack(t_stack_node **stack_a, t_stack_node *node)
{
	t_stack_node	*last;

	if (!*stack_a)
		*stack_a = node;
	else
	{
		last = *stack_a;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = node;
		node->next = NULL;
		node->prev = last;
	}
}

t_stack_node	*nbr_to_node(int nbr)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return (NULL);
	node->value = nbr;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	check_if_exist(t_stack_node **stack_a, int nbr)
{
	t_stack_node	*current;

	current = *stack_a;
	while (current != NULL)
	{
		if (current->value == nbr)
			return (-1);
		current = current->next;
	}
	return (0);
}

int	convert_to_nbr(t_stack_node **stack_a, char **taking_value)
{
	int				j;
	int				nbr;
	t_stack_node	*node;

	j = 0;
	while (taking_value[j])
	{
		nbr = ft_atoi(taking_value[j]);
		if (check_if_exist(stack_a, nbr) == -1)
			return (-1);
		else
		{
			node = nbr_to_node(nbr);
			if (node == NULL)
				return (-1);
			node_to_stack(stack_a, node);
		}
		j++;
	}
	return (0);
}
