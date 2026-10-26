/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:37:42 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/26 17:40:07 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	execute_movements_two(char *line, t_data *data)
{
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
	{
		rotatereverse(&data->stack_a);
		rotatereverse(&data->stack_b);
	}
	else if (line[0] == 'r' && line[1] == 'r')
	{
		rotate(&data->stack_a);
		rotate(&data->stack_b);
	}
	else if (line[0] == 's' && line[1] == 'a')
		swap(&data->stack_a);
	else if (line[0] == 's' && line[1] == 'b')
		swap(&data->stack_b);
	else if (line[0] == 's' && line[1] == 's')
	{
		swap(&data->stack_a);
		swap(&data->stack_b);
	}
}

static void	execute_movements(char *line, t_data *data)
{
	if (line[0] == 'p' && line[1] == 'a')
		push(&data->stack_b, &data->stack_a);
	else if (line[0] == 'p' && line[1] == 'b')
		push(&data->stack_a, &data->stack_b);
	else if (line[0] == 'r' && line[1] == 'a')
		rotate(&data->stack_a);
	else if (line[0] == 'r' && line[1] == 'b')
		rotate(&data->stack_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		rotatereverse(&data->stack_a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		rotatereverse(&data->stack_b);
	else
		execute_movements_two(line, data);
}

static int	check_all_good(t_data *data)
{
	if (!data->stack_b)
	{
		data->disorder = cal_index_error(data);
		if (data->disorder == 0)
			return (0);
		else
			return (-1);
	}
	else
		return (-1);
}

static void	free_stacks(t_data *data)
{
	parser_free(NULL, data->stack_a);
	parser_free(NULL, data->stack_b);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*line;

	start(&data);
	if (!parser(argc, argv, &data) || !data.stack_a)
		return (ft_putstr_fd("Error\n", 2), parser_free(NULL, data.stack_a), 1);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (parser_movements(line) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (free(line), free_stacks(&data), 1);
		}
		execute_movements(line, &data);
		free(line);
		line = get_next_line(0);
	}
	if (check_all_good(&data) == -1)
		return (ft_putstr_fd("KO\n", 1), free_stacks(&data), 1);
	else
		return (ft_putstr_fd("OK\n", 1), free_stacks(&data), 0);
}
