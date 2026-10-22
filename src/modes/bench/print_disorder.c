/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:09:20 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/21 19:40:26 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	print_disorder(double disorder)
{
	double	temp;
	int		before_dot;
	int		after_dot;

	temp = disorder;
	temp = temp * 100;
	before_dot = (int)temp;
	temp = temp - before_dot;
	temp = temp * 100;
	after_dot = (int)temp;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(before_dot, 2);
	ft_putchar_fd('.', 2);
	if (after_dot < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(after_dot, 2);
	ft_putchar_fd('\n', 2);
}
