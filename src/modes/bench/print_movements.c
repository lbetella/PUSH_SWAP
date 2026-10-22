/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 19:33:01 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/21 19:40:48 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	first(t_data *data)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd("sa: ", 2);
	ft_putnbr_fd(data->sa, 2);
	ft_putchar(' ', 2);
	ft_putstr_fd("sb: ", 2);
	ft_putnbr_fd(data->sb, 2);
	ft_putchar(' ', 2);
	ft_putstr_fd("ss: ", 2);
	ft_putnbr_fd(data->ss, 2);
	ft_putchar(' ', 2);
	ft_putstr_fd("pa: ", 2);
	ft_putnbr_fd(data->pa, 2);
	ft_putchar(' ', 2);
	ft_putstr_fd("pb: ", 2);
	ft_putnbr_fd(data->pb, 2);
	ft_putchar_fd('\n', 2);
}

static void	second(t_data *data)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd("ra: ", 2);
	ft_putnbr_fd(data->ra, 2);
	ft_putchar(' ', 2);
	ft_putstr_fd("rb: ", 2);
	ft_putnbr_fd(data->rb, 2);
	ft_putchar(' ', 2);
	ft_putstr_fd("rr: ", 2);
	ft_putnbr_fd(data->rr, 2);
	ft_putchar(' ', 2);
	ft_putstr_fd("rra: ", 2);
	ft_putnbr_fd(data->rra, 2);
	ft_putchar(' ', 2);
	ft_putstr_fd("rrb: ", 2);
	ft_putnbr_fd(data->rrb, 2);
	ft_putchar(' ', 2);
	ft_putstr_fd("rrr: ", 2);
	ft_putnbr_fd(data->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	print_movements(t_data *data)
{
	first(data);
	second(data);
}
