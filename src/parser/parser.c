/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parser.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: lbetella <lbetella@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/17 17:36:03 by lbetella         #+#    #+#              */
/*   Updated: 2026/10/20 19:35:33 by lbetella        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_space_number(char *argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (-1);
	while ((argv[i] >= 9 && argv[i] <= 13) || argv[i] == 32)
		i++;
	if (argv[i] == '\0')
		return (-1);
	else
		return (0);
}

int	check_limits_numbers(char *nb)
{
	int	len;

	len = ft_strlen(nb);
	if (nb[0] == '-')
	{
		if (len > 11)
			return (-1);
		else if (len == 11 && ft_strncmp(&nb[1], "2147483647", 10) > 0)
			return (-1);
	}
	else
	{
		if (nb[0] == '+')
		{
			nb++;
			len--;
		}
		if (len > 10)
			return (-1);
		else if (len == 10 && ft_strncmp(nb, "2147483647", 10) > 0)
			return (-1);
	}
	return (0);
}

int	check_definitive_numbers(char **nb)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (nb[j])
	{
		i = 0;
		while (nb[j][i] != '\0')
		{
			if (!(nb[j][i] >= '0' && nb[j][i] <= '9') && !(nb[j][i] == '-'
						|| nb[j][i] == '+'))
				return (-1);
			if (nb[j][i] == '-' || nb[j][i] == '+')
			{
				if (i > 0 || nb[j][i + 1] == '\0')
					return (-1);
			}
			if (check_limits_numbers(nb[j]) == -1)
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

char	**replace_tabs(char **argv)
{
	int	i;
	int	j;

	j = 0;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (argv[j][i] >= 9 && argv[j][i] <= 13)
				argv[j][i] = ' ';
			i++;
		}
		j++;
	}
	return (argv);
}

int	parser(int argc, char **argv, t_data *data)
{
	int		i;
	int		check;
	char	**taking_value;

	i = 0;
	argv = replace_tabs(argv);
	while (++i < argc)
	{
		check = check_flags(argv[i], &data->mode, &data->bench);
		if (check == -1)
			return (0);
		else if (check == 0)
		{
			if (check_space_number(argv[i]) == -1)
				return (0);
			taking_value = ft_split(argv[i], ' ');
			if (check_definitive_numbers(taking_value) == -1
				|| taking_value == NULL)
				return (parser_free(taking_value, NULL), 0);
			if (convert_to_nbr(&data->stack_a, taking_value) == -1)
				return (parser_free(taking_value, NULL), 0);
			parser_free(taking_value, NULL);
		}
	}
	return (1);
}
