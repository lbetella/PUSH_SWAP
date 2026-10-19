/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:18:00 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/19 17:39:45 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void parser_free(char **taking_value, t_stack_node *stack_a)
{
    int i;
    t_stack_node *temp;
    t_stack_node *head;
    
    i = 0;
    if (taking_value)
    {
        while (taking_value[i])
        {
            free(taking_value[i]);
            i++;
        }
        free(taking_value);
    }
    if (stack_a)
    {
        head = stack_a;
        head->prev->next = NULL;
        while (head)
        {
            temp = head->next;
            free(head);
            head = temp;
        }
    }
}
