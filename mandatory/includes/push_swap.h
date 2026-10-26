/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilfran <guilfran@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:58:07 by lbetella          #+#    #+#             */
/*   Updated: 2026/10/23 19:44:00 by guilfran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libs/libft.h"
# include <limits.h>
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
	double				disorder;
	int					total_ops;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
	int					p[11];
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
void					pa(t_data *data);
void					pb(t_data *data);
int						push(t_stack_node **stack1, t_stack_node **stack2);
void					ra(t_data *data);
void					rb(t_data *data);
int						rotate(t_stack_node **stack);
int						rotatereverse(t_stack_node **stack);
void					rr(t_data *data);
void					rra(t_data *data);
void					rrb(t_data *data);
void					rrr(t_data *data);
void					sa(t_data *data);
void					sb(t_data *data);
void					ss(t_data *data);
int						swap(t_stack_node **head);
void					adaptive_mode(t_data *data);
void					bench_mode(t_data *data);
void					simple_mode(t_data *data);
void					complex_mode(t_data *data);
void					medium_mode(t_data *data);
int						pos_upper_len(t_stack_node **stack);
void					parser_free(char **taking_value, t_stack_node *stack_a);
void					cal_index(t_stack_node *stack);
int						get_chunk_size(int size);
int						stack_len(t_stack_node *stack_a);
int						get_max_pos(t_stack_node *stack_b);
void					order_three_numbers(t_data *data);
void					send_to_b(t_data *data, int min, int chunk_size);
void					send_to_a(t_data *data);
void					look_for_target(t_stack_node *stack_a,
							t_stack_node *stack_b);
t_stack_node			*cost(t_stack_node **stack_a, t_stack_node **stack_b);
void					both_up(t_data *data, t_stack_node *to_move);
void					both_down(t_data *data, t_stack_node *to_move);
void					b_down(t_data *data, t_stack_node *to_move);
void					a_down(t_data *data, t_stack_node *to_move);
double					cal_index_error(t_data *data);
void					start(t_data *data);
void					print_disorder(double disorder);
void					print_strategy(int mode, double disorder);
void					print_total(int total_ops);
void					print_movements(t_data *data);
void					pivot(t_data *data, int len_a);
void					b_to_a_complex(t_data *data);
void					move_to_b(t_data *data, t_stack_node *choosen);
void					less_than_five(t_data *data, int len_a);
void					reverse_two_numbers_b(t_data *data);
#endif
