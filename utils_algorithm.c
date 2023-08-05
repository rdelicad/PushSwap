/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:37:48 by lxuxer            #+#    #+#             */
/*   Updated: 2023/08/05 22:41:35 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	algorithm(t_list **stack_a, t_list **stack_b, t_struct result)
{
	//int	cont;
	int	medi;

	medi = median(result.argsi, result.len);
	//cont = 0;
	if (is_sorted(*stack_a))
		print_movements(*stack_a, *stack_b);
	else if (ft_lstsize(*stack_a) == 2)
	{
		swap_stack(stack_a);
		print_movements(*stack_a, *stack_b);
	}
	else if (ft_lstsize(*stack_a) == 3)
	{
		tiny_sort(stack_a, stack_b);
	}
	else if (ft_lstsize(*stack_a) > 3)
	{
		two_towers(stack_a, stack_b, medi);
		tiny_sort(stack_a, stack_b);
		two_towers1(stack_a, stack_b, result.len);
	}
	ft_printf("Mediana: %d\n", medi);
}


void	tiny_sort(t_list **stack_a, t_list **stack_b)
{
	int	a;
	int	b;
	int	c;

	while (!is_sorted(*stack_a))
	{
		a = *((*stack_a)->content);
		b = *((*stack_a)->next->content);
		c = *((*stack_a)->next->next->content);
		if (a > b && a < c)
			swap_stack(stack_a);
		else if (a > b && a > c)
			rotate_stack(stack_a);
		else if ((a < b && a > c) || (a < b && a < c && b > c))
			reverse_stack(stack_a);
	}
	print_movements(*stack_a, *stack_b);
}

void	two_towers(t_list **stack_a, t_list **stack_b, int medi)
{
	int	i;
	int	len_a;
	int	len_b;
	int	top;
	int	flag;

	flag = 0;
	top = 0;
	i = 0;
	len_a = stack_len(*stack_a);
	while (i < len_a - 3)
	{
		len_b = stack_len(*stack_b);
		if (*((*stack_a)->content) > medi && top < 3)
		{
			rotate_stack(stack_a);
			top++;
			flag = 1;
		}
		else
		{
			push_stack(stack_a, stack_b);
			i++;
		}
		if (len_b > 1 && *((*stack_b)->content) <= medi && flag == 0)
		{
			rotate_stack(stack_b);
		}
		flag = 0;
	}
	print_movements(*stack_a, *stack_b);
}

void	two_towers1(t_list **stack_a, t_list **stack_b, int len)
{
	t_list	*current;
	int	target;

	current = *stack_b;
	target = cost_target(*stack_a, *stack_b, len);
	ft_printf("target a mover: %d\n", target);
	//move_stack_a(stack_a, target);
	while (current && current->target != target)
	{
		rotate_stack(stack_b);
		current = (*stack_b);
	}
	if (current && current->target == target)
		push_stack(stack_b, stack_a);
	
	print_movements(*stack_a, *stack_b);
	target = cost_target(*stack_a, *stack_b, len);
	ft_printf("target a mover: %d\n", target);
}
