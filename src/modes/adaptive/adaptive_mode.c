/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 18:14:19 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/21 18:06:29 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	adaptive_mode(t_data *data)
{
	if (data->disorder < 0.2)
		simple_mode(data);
	else if (data->disorder >= 0.2 && data->disorder < 0.5)
		medium_mode(data);
	else if (data->disorder >= 0.5)
		complex_mode(data);
}
