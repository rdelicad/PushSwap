/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:37:48 by lxuxer            #+#    #+#             */
/*   Updated: 2023/08/16 21:39:33 by rdelicad         ###   ########.fr       */
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
		tiny_sort(stack_a, stack_b);
		//two_towers1(stack_a, stack_b);
		while ((*stack_b) != NULL)
			two_towers1(stack_a, stack_b);
		two_towers2(stack_a, stack_b);
	}
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
	(void)medi;
	ft_split_stack(stack_a, stack_b);
	// t_tower t;

	// t.flag = 0;
	// t.top = 0;
	// t.i = 0;
	// t.len_a = stack_len(*stack_a);
	// while (t.i < t.len_a - 3)
	// {
	// 	t.len_b = stack_len(*stack_b);
	// 	if (*((*stack_a)->content) > medi && t.top++ < 3)
	// 	{
	// 		rotate_a(stack_a);
	// 		t.flag = 1;
	// 	}
	// 	else
	// 	{
	// 		push_b(stack_a, stack_b);
	// 		t.i++;
	// 	}
	// 	if (t.len_b > 1 && *((*stack_b)->content) <= medi && t.flag == 0)
	// 	{
	// 		if (*((*stack_b)->next->content) > medi)
	// 			rotate_b(stack_b);
	// 	}
	// 	t.flag = 0;
	// }
	print_movements(*stack_a, *stack_b);
}

void two_towers1(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	t_cost	c;

	c.target_b = get_min_cost(*stack_a, *stack_b);
	c.target_a = search_target_a(stack_a, c.target_b);
	// for (t_list *curr = *stack_a; curr != NULL; curr = curr->next)
	// {
	// 	if (curr->target == c.target_a)
	// 	{
	// 		c.target_a = curr->target;
	// 		c.content_a = *curr->content;
	// 		break;
	// 	}
	// }
	// for (t_list *curre = *stack_b; curre != NULL; curre = curre->next)
	// {
	// 	if (curre->target == c.target_b)
	// 	{
	// 		c.target_b = curre->target;
	// 		c.content_b = *curre->content;
	// 		break;
	// 	}
	// }
	// ft_printf("mover target_a: %d, content_a: %d\n", c.target_a, c.content_a);
	// ft_printf("mover target_b: %d, content_b: %d\n", c.target_b, c.content_b);
	current = *stack_b;
	while (current != NULL)
	{
		if (current->target == c.target_b)
		{
			c.costa = current->costa;
			c.costb = current->costb;
			break;
		}
		current = current->next;
	}
	move(stack_a, stack_b, c.costa, c.costb);
	//print_movements(*stack_a, *stack_b);
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
