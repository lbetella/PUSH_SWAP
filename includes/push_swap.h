/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:58:07 by guilfran          #+#    #+#             */
/*   Updated: 2026/10/19 19:00:58 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libs/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					pos;
	int					upper;
	struct s_stack_node	*target_node;
	int					cost_a;
	int					cost_b;
	int					cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

typedef struct s_data
{
	int					mode;
	int					bench;
	t_stack_node		*stack_a;
	t_stack_node		*stack_b;
}						t_data;

int						parser(int argc, char **argv, t_data *data);
int						check_definitive_numbers(char **nb);
int						check_limits_numbers(char *nb);
int						check_space_number(char *argv);
int						check_flags(char *argv, int *mode, int *bench);
int						check_if_exist(t_stack_node **stack_a, int nbr);
int						convert_to_nbr(t_stack_node **stack_a,
							char **taking_value);
void					node_to_stack(t_stack_node **stack_a,
							t_stack_node *node);
t_stack_node			*nbr_to_node(int nbr);
void					mode_selector(t_data *data);
void					pa(t_stack_node **stack_a, t_stack_node **stack_b);
void					pb(t_stack_node **stack_a, t_stack_node **stack_b);
int						push(t_stack_node **stack1, t_stack_node **stack2);
void					ra(t_stack_node **stack_a);
void					rb(t_stack_node **stack_b);
int						rotate(t_stack_node **stack);
int						rotatereverse(t_stack_node **stack);
void					rr(t_stack_node **stack_a, t_stack_node **stack_b);
void					rra(t_stack_node **stack_a);
void					rrb(t_stack_node **stack_b);
void					rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void					sa(t_stack_node **stack_a);
void					sb(t_stack_node **stack_b);
void					ss(t_stack_node **stack_a, t_stack_node **stack_b);
int						swap(t_stack_node **head);
void					adaptive_mode(t_data *data);
void					bench_mode(t_data *data);
void					simple_mode(t_data *data);
void					complex_mode(t_data *data);
void					medium_mode(t_data *data);
int						pos_upper_len(t_stack_node **stack);
void					parser_free(char **taking_value, t_stack_node *stack_a);
void					cal_index(t_stack_node *stack);

#endif