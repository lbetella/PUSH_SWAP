/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 13:34:28 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/26 14:29:11 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	parser_movements(char *line)
{
	if (ft_strncmp(line, "pa\n", 4) == 0)
		return (0);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		return (0);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		return (0);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		return (0);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		return (0);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		return (0);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (0);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		return (0);
	else if (ft_strncmp(line, "sa\n", 4) == 0)
		return (0);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		return (0);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		return (0);
	else
		return (-1);
}
