/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:58:07 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/26 16:26:48 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../../mandatory/includes/push_swap.h"
# include "libs/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

int		parser_movements(char *line);
void	start(t_data *data);
double	cal_index_error(t_data *data);
void	cal_index(t_stack_node *stack);

#endif
