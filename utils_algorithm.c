/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:37:48 by lxuxer            #+#    #+#             */
/*   Updated: 2023/08/03 11:19:54 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	algorithm(t_list *stack_a, t_list *stack_b, t_struct result)
{
	//int	cont;
	int	medi;

	medi = median(result.argsi, result.len);
	//cont = 0;
	// if (is_sorted(stack_a))
	// 	print_movements(stack_a, stack_b);
	if (ft_lstsize(stack_a) == 2)
	{
		swap_stack(&stack_a);
		print_movements(stack_a, stack_b);
	}
	else if (ft_lstsize(stack_a) == 3)
	{
		tiny_sort(stack_a, stack_b);
	}
	else if (ft_lstsize(stack_a) > 3)
	{
		stack_b = two_towers(stack_a, stack_b, medi);
		tiny_sort(stack_a, stack_b);
		two_towers1(stack_a, stack_b);
	}
}


void	tiny_sort(t_list *stack_a, t_list *stack_b)
{
	int	a;
	int	b;
	int	c;

	while (!is_sorted(stack_a))
	{
		a = *stack_a->content;
		b = *stack_a->next->content;
		c = *stack_a->next->next->content;
		if (a > b && a < c)
			swap_stack(&stack_a);
		else if (a > b && a > c)
			rotate_stack(&stack_a);
		else if ((a < b && a > c) || (a < b && a < c && b > c))
			reverse_stack(&stack_a);
		//else
		//	break ;
	}
	print_movements(stack_a, stack_b);
}

t_list	*two_towers(t_list *stack_a, t_list *stack_b, int medi)
{
	int	i;
	int	len;
	int	top;

	len = stack_len(stack_a) - 3;
	i = 0;
	top = 0;
	while (i < len)
	{
		if (*stack_a->content > medi && top < 3)
		{
			rotate_stack(&stack_a);
			top++;
		}
		push_stack(&stack_a, &stack_b);
		if (stack_b != NULL && *stack_b->content <= medi)
		{
			rotate_stack(&stack_b);
		}
		i++;
	}
	print_movements(stack_a, stack_b);
	return (stack_b);
}

void	two_towers1(t_list *stack_a, t_list *stack_b)
{
	int	target;

	target = cost_target(stack_a, stack_b);
	ft_printf("target a mover: %d", target);
	//print_movements(stack_a, stack_b);
}