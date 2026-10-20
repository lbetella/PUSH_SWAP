/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:37:42 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/20 13:57:50 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	main(int argc, char **argv)
// {
// 	t_data	data;

// 	data.mode = 0;
// 	data.bench = 0;
// 	data.stack_a = NULL;
// 	data.stack_b = NULL;
// 	if (argc < 2 || !parser(argc, argv, &data) || !data.stack_a)
// 	{
// 		ft_printf("Error\n");
//		parser_free(NULL, data.stack_a);
// 		return (1);
// 	}
// 	else
// 	{
// 		ft_printf("Modo: %i\nBench: %i\n", data.mode, data.bench);
// 		mode_selector(&data);
// 	}
// 	return (0);
// }


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

	// Inicialización de la estructura de datos
	data.mode = 0;
	data.bench = 0;
	data.stack_a = NULL;
	data.stack_b = NULL;

	// Si no hay argumentos suficientes, salimos limpiamente
	if (argc < 2)
		return (0);

	// Validación de argumentos y parsing
	if (!parser(argc, argv, &data) || !data.stack_a)
	{
		ft_printf("Error\n");
		parser_free(NULL, data.stack_a);
		return (1);
	}

	mode_selector(&data);

	// Comprobación visual de que el parsing y las flags han funcionado
	//ft_printf("[DEBUG] Modo: %i | Bench: %i\n", data.mode, data.bench);


	//ft_print_stack("A", data.stack_a);
	//ft_print_stack("B", data.stack_b);

	// Ejecución del selector de algoritmos
	// ...

	parser_free(NULL, data.stack_a);
	// (Opcional pero recomendable) Liberar también stack_b si contiene elementos
	// parser_free(NULL, data.stack_b);

	return (0);
}
