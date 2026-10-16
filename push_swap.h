/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:58:07 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/16 17:08:48 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack_node {
    int                     value;        // Valor entero original
    int                     index;        // Índice de orden relativo (1 a N)
    int                     pos;          // Posición actual en el stack (0 a size-1)
    int                     upper;        // 1 si está en la mitad superior, 0 si está abajo
    struct s_stack_node    *target_node;  // Puntero al nodo objetivo en la otra pila
    int                     cost_a;       // Acciones requeridas en el Stack A
    int                     cost_b;       // Acciones requeridas en el Stack B
    int                     cheapest;     // 1 si es el elemento más barato de mover, 0 si no
    struct s_stack_node    *next;
    struct s_stack_node    *prev;
} t_stack_node;

#endif