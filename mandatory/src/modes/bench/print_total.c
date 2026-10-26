/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 19:27:25 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/21 19:29:25 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	print_total(int total_ops)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops, 2);
	ft_putchar_fd('\n', 2);
}
