/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strategy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 19:10:25 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/21 19:29:18 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	print_strategy(int mode, double disorder)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (mode == 1)
		ft_putstr_fd("Simple / O(n²)", 2);
	else if (mode == 2)
		ft_putstr_fd("Medium / O(n√n)", 2);
	else if (mode == 3)
		ft_putstr_fd("Complex / O(n log n)", 2);
	else if (mode == 4 || mode == 0)
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (disorder < 0.2)
			ft_putstr_fd("O(n²)", 2);
		else if (disorder >= 0.2 && disorder < 0.5)
			ft_putstr_fd("O(n√n)", 2);
		else if (disorder >= 0.5)
			ft_putstr_fd("O(n log n)", 2);
	}
	ft_putchar_fd('\n', 2);
}
