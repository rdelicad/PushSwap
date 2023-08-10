/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:37:48 by lxuxer            #+#    #+#             */
/*   Updated: 2023/08/10 23:00:37 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void algorithm(t_list **stack_a, t_list **stack_b, t_struct result)
{
	int medi;

	medi = median(result.argsi, result.len);
	if (is_sorted(*stack_a))
		print_movements(*stack_a, *stack_b);
	else if (ft_lstsize(*stack_a) == 2)
	{
		swap_a(stack_a);
		print_movements(*stack_a, *stack_b);
	}
	else if (ft_lstsize(*stack_a) == 3)
	{
		tiny_sort(stack_a, stack_b);
	}
	else if (ft_lstsize(*stack_a) > 3)
	{
		two_towers(stack_a, stack_b, medi);
		// ft_printf("--%d--", *((*stack_a)->content));
		tiny_sort(stack_a, stack_b);
		two_towers1(stack_a, stack_b, result.len);
		while ((*stack_b) != NULL)
			two_towers1(stack_a, stack_b, result.len);
		two_towers2(stack_a, stack_b);
	}
	// ft_printf("--%d--", *((*stack_a)->content));
	//  ft_printf("Mediana: %d\n", medi);
}

void tiny_sort(t_list **stack_a, t_list **stack_b)
{
	int a;
	int b;
	int c;
	(void)*stack_b;

	while (!is_sorted(*stack_a))
	{
		a = *((*stack_a)->content);
		b = *((*stack_a)->next->content);
		c = *((*stack_a)->next->next->content);
		if (a > b && a < c)
			swap_a(stack_a);
		else if (a > b && a > c)
			rotate_a(stack_a);
		else if ((a < b && a > c) || (a < b && a < c && b > c))
			reverse_a(stack_a);
	}
	print_movements(*stack_a, *stack_b);
}

void two_towers(t_list **stack_a, t_list **stack_b, int medi)
{
	t_tower t;

	t.flag = 0;
	t.top = 0;
	t.i = 0;
	t.len_a = stack_len(*stack_a);
	while (t.i < t.len_a - 3)
	{
		t.len_b = stack_len(*stack_b);
		if (*((*stack_a)->content) > medi && t.top++ < 3)
		{
			rotate_a(stack_a);
			t.flag = 1;
		}
		else
		{
			push_b(stack_a, stack_b);
			t.i++;
		}
		if (t.len_b > 1 && *((*stack_b)->content) <= medi && t.flag == 0)
		{
			if (*((*stack_b)->next->content) > medi)
				rotate_b(stack_b);
		}
		t.flag = 0;
	}
	print_movements(*stack_a, *stack_b);
}

void two_towers1(t_list **stack_a, t_list **stack_b, int len)
{
	t_list *current;

	current = *stack_b;
	get_cost_target(*stack_a, *stack_b, len);
	





	// move_stack_a(stack_a, target_b);
	// while (current && current->target != target_b)
	// {
	// 	rotate_b(stack_b);
	// 	current = (*stack_b);
	// }
	// if (current && current->target == target_b)
	// 	push_a(stack_b, stack_a);
	// print_movements(*stack_a, *stack_b);
}

void two_towers2(t_list **stack_a, t_list **stack_b)
{
	if (!is_sorted(*stack_a))
	// ft_printf("Todo correcto\n");
	// else
	{
		while ((*stack_a)->target != 0)
		{
			reverse_a(stack_a);
			if ((*stack_a)->target == 1)
				break;
		}
	}
	print_movements(*stack_a, *stack_b);
}
