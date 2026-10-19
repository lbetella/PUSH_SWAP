/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:44:02 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/19 18:02:05 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_flags(char *argv, int *mode, int *bench)
{
	if (argv && argv[0] == '-' && argv[1] == '-')
	{
		if (ft_strncmp(argv, "--simple", 9) == 0 && *mode == 0)
			*mode = 1;
		else if (ft_strncmp(argv, "--medium", 9) == 0 && *mode == 0)
			*mode = 2;
		else if (ft_strncmp(argv, "--complex", 10) == 0 && *mode == 0)
			*mode = 3;
		else if (ft_strncmp(argv, "--adaptive", 11) == 0 && *mode == 0)
			*mode = 4;
		else if (ft_strncmp(argv, "--bench", 8) == 0 && *bench == 0)
			*bench = 1;
		else
			return (-1);
		return (1);
	}
	return (0);
}

void	node_to_stack(t_stack_node **stack_a, t_stack_node *node)
{
	t_stack_node	*last;

	if (!*stack_a)
		*stack_a = node;
	else
	{
		last = (*stack_a)->prev;
		last->next = node;
		node->prev = last;
		node->next = *stack_a;
		(*stack_a)->prev = node;
	}
}

t_stack_node	*nbr_to_node(int nbr)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return (NULL);
	node->value = nbr;
	node->next = node;
	node->prev = node;
	return (node);
}

int	check_if_exist(t_stack_node **stack_a, int nbr)
{
	t_stack_node	*current;
	int	first;

	if (!stack_a || !*stack_a)
		return(0);
	first = 1;
	current = *stack_a;
	while (current != *stack_a || first == 1)
	{
		if (current->value == nbr)
			return (-1);
		current = current->next;
		first = 0;
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
