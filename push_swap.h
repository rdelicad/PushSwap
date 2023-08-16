/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:39:22 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/15 21:50:25 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_struct
{
	int	*argsi;
	int	len;
	int	nodes_a;
	int	cont;
}	t_struct;

typedef struct s_cost
{
	int content_a;
	int content_b;
	int	target_a;
	int	target_b;
	int	min_cost;
	int	total_cost;
	int len_stack;
	int	half;
	int	content;
	int	costa;
	int	costb;
	int	i;
}	t_cost;

typedef struct s_tower
{
	int	i;
	int	len_a;
	int	len_b;
	int	top;
	int	flag;
}	t_tower;

typedef struct s_move
{
	int	target_a;
	int	posit;
	int	len;
}	t_move;

typedef struct s_search_a
{
	int min;
	int	diff;
	int	target_a;
	int	min_lower;
	int min_upper;
}	t_search;

/* push_swap.c */
int			characters(char **args);
int			duplicates(char **args);
char		**valid_args(int ac, char **av);
t_struct	convert_int_args(char **args);
void		leaks(void);

/* utils_nodes.c */
t_list		*create_stack_a(int *argsi, int len);
t_list		*create_nodes(int *argsi, int len);
int			get_position(t_list **stack_a, int node_value);
void		assign_target(t_list **stack_a);

/* utils_stack.c */
void		free_memory_split(int ac, int i, char **args);
void		free_memory_stacks(int *argsi, t_list *stack_a, t_list *stack_b);
t_list		*end_stack(t_list *stack);
int			is_sorted(t_list *stack);
int			stack_len(t_list *stack);

/* utils_movements.c */
t_list		*print_movements(t_list *stack_a, t_list *stack_b);


/* utils_swap.c */
void		swap_stack(t_list **stack);
void		swap_a(t_list **stack_a);
void		swap_b(t_list **stack_b);
void		swap_s(t_list **stack_a, t_list **stack_b);

/* utils_rotate.c */
void		rotate_stack(t_list **stack_init);
void		rotate_a(t_list **stack_a);
void		rotate_b(t_list **stack_b);
void		rotate_r(t_list **stack_a, t_list **stack_b);

/* utils_push.c */
void		push_stack(t_list **stack_init, t_list **stack_end);
void		push_a(t_list **stack_a, t_list **stack_b);
void		push_b(t_list **stack_b, t_list **stack_a);

/* utils_reverse.c */
void		reverse_stack(t_list **stack_head);
void		reverse_a(t_list **stack_a);
void		reverse_b(t_list **stack_b);
void		reverse_r(t_list **stack_a, t_list **stack_b);


/* Utils_algorithm.c */
void		algorithm(t_list **stack_a, t_list **stack_b, t_struct result);
void		tiny_sort(t_list **stack_a, t_list **stack_b);
void		two_towers(t_list **stack_a, t_list **stack_b, int medi);
void		two_towers1(t_list **stack_a, t_list **stack_b);
void		two_towers2(t_list **stack_a, t_list **stack_b);

/* utils_cost.c */
void		costb(t_list *stack_b);
int			costa(t_list *stack_a, int target_b);
int			search_lower_a(t_list *stack_a, int target_b);
int			search_upper_a(t_list *stack_a, int target_b);
void		assig_cost_nodes(t_list *stack_a, t_list *stack_b);

/* utils_cost1.c */
void		get_cost_total(t_list *stack_b);
int			get_min_cost(t_list *stack_a, t_list *stack_b);

/* utils_towers.c */
int			half(t_list *stack);
int			median(int *argsi, int len);
int			*copy_argsi(int *argsi, int len);
int			search_target_a(t_list **stack_a, int target);
int			position_target_a(t_list *stack_a, int  target_a);

/* utils_move_a.c */
void		move_node_a(t_list **stack_a, t_list **stack_b, int a);
void		rotate_node_a(t_list **stack_a, t_list **stack_b, int a);
void		reverse_node_a(t_list **stack_a, t_list **stack_b, int a);

/* utils_move_b.c */
void		move_node_b(t_list **stack_a, t_list **stack_b, int b);
void		rotate_node_b(t_list **stack_a, t_list **stack_b, int b);
void		reverse_node_b(t_list **stack_a, t_list **stack_b, int b);

/* utils_rotates_nodes.c */
void		reverse_rotate(t_list **stack_a, t_list **stack_b, int a, int b);
void		ra_mayor_b(t_list **stack_a, t_list **stack_b, int a, int b);
void		ra_minor_b(t_list **stack_a, t_list **stack_b, int a, int b);
void		rr_ab(t_list **stack_a, t_list **stack_b, int b);

/* utils_reverses_nodes.c */
void		reverse_reverse(t_list **stack_a, t_list **stack_b, int a, int b);
void		rra_mayor_b(t_list **stack_a, t_list **stack_b, int a, int b);
void		rra_minor_b(t_list **stack_a, t_list **stack_b, int a, int b);
void    	rrr_ab(t_list **stack_a, t_list **stack_b, int b);

/* utils_move.c */
void		move(t_list **stack_a, t_list **stack_b, int a, int b);

#endif