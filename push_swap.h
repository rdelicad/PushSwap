/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:39:22 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/04 10:42:45 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_struct
{
	int	*argsi;
	int	len;
	int	cont;
}	t_struct;

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
void		swap_stack(t_list **stack);
void		push_stack(t_list **stack_init, t_list **stack_end);
void		rotate_stack(t_list **stack_init);
void		reverse_stack(t_list **stack_head);
t_list		*print_movements(t_list *stack_a, t_list *stack_b);

/* Utils_algorithm.c */
void		algorithm(t_list **stack_a, t_list **stack_b, t_struct result);
void		tiny_sort(t_list **stack_a, t_list **stack_b);
void		two_towers(t_list **stack_a, t_list **stack_b, int medi);
void		two_towers1(t_list **stack_a, t_list **stack_b, int len);

/* utils_towers.c */
int			half(t_list *stack);
int			median(int *argsi, int len);
int			*copy_argsi(int *argsi, int len);

/* utils_cost.c */
int			distance(int a, int b, int len);
int			costb(t_list *stack_b, int target);
int			costa(t_list *stack_a, int target_b, int len);
int			search_target_a(t_list *stack_a, int target_b, int len);
int			cost_target(t_list *a, t_list *b, int len);

#endif