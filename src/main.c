/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:37:42 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/24 18:05:38 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static void	ft_print_stack(char *name, t_stack_node *stack)
// {
// 	t_stack_node	*current;
// 	int				first;

// 	ft_printf("=== STACK %s ===\n", name);
// 	if (!stack)
// 	{
// 		ft_printf("(vacía)\n");
// 		ft_printf("================\n");
// 		return ;
// 	}
// 	current = stack;
// 	first = 1;
// 	while (current != stack || first)
// 	{
// 		ft_printf("Value: %d | Index: %d\n", current->value, current->index);
// 		current = current->next;
// 		first = 0;
// 	}
// 	ft_printf("================\n");
// }

int	main(int argc, char **argv)
{
	t_data data;
	int len_a;
	
	start(&data);

	if (argc < 2)
		return (0);

	if (!parser(argc, argv, &data) || !data.stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		parser_free(NULL, data.stack_a);
		return (1);
	}
	cal_index(data.stack_a);
	data.disorder = cal_index_error(&data);
	if (data.disorder == 0)
		return (0);
	len_a = pos_upper_len(&data.stack_a);
	if (len_a <= 5)
		less_than_five(&data, len_a);
	else
		mode_selector(&data);

	// ft_printf("[DEBUG] Modo: %i | Bench: %i\n", data.mode, data.bench);
	// ft_print_stack("A", data.stack_a);
	// ft_print_stack("B", data.stack_b);

	parser_free(NULL, data.stack_a);
	return (0);
}
