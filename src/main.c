/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:37:42 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/19 18:06:14 by guilfran         ###   ########.fr       */
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

// Función auxiliar para imprimir el stack_a (y comprobar el parsing)
static void	ft_print_stack_a(t_stack_node *stack_a)
{
	t_stack_node	*current;
	int				first;

	ft_printf("=== STACK A ===\n");
	if (!stack_a)
		return ;
	current = stack_a;
	first = 1;
	while (current != stack_a || first)
	{
		ft_printf("%d\n", current->value); // O tu forma de imprimir
		current = current->next;
		first = 0;
	}
	ft_printf("===============\n");
}

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

	// Comprobación visual de que el parsing y las flags han funcionado
	ft_printf("[DEBUG] Modo: %i | Bench: %i\n", data.mode, data.bench);
	ft_print_stack_a(data.stack_a);

	// Ejecución del selector de algoritmos
	mode_selector(&data);

	parser_free(NULL, data.stack_a);

	return (0);
}