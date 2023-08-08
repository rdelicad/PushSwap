/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:25:33 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/08 13:19:48 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int costb(t_list *stack_b, int target, int len)
{
    t_list  *current;
	t_cost	c;

    len = stack_len(stack_b);
    c.half = half(stack_b);
    c.costb = 0;
    current = stack_b;
    while (current != NULL)
    {
        if (current->target == target)
        {
            if (c.costb <= c.half)
                return (c.costb);
            else
                return (len - c.costb - 1);
        }
        c.costb++;
    }
    return (c.costb);
}

int	search_target_a(t_list *stack_a, int target_b)
{
	t_list	*current;
	int		min_distance;
	int		target_a;
	int		dist;
	int		lower;

	lower = INT_MIN;
	target_a = 0;
	min_distance = INT_MAX;
	current = stack_a;
	while (current != NULL)
	{
		dist = distance(current->target, target_b);
		if (dist <= min_distance)
		{
			min_distance = dist;
			target_a = current->target;
		}
		if (current->target < target_b && current->target > lower)
			lower = current->target;
		current = current->next;
	}
	if (lower != INT_MIN)
		target_a = lower;
	/* ft_printf ("target a: %d\n", target_a); */
	return (target_a);
}

int	distance(int a, int b)
{
    int	dist;

	dist = a - b;
	if (dist < 0) 
		dist *= -1;  
	return (dist);
}

int	costa(t_list *stack_a, int target_b)
{
	t_list	*current;
	t_cost	c;

	c.len_stack = stack_len(stack_a);
	c.target_a = search_target_a(stack_a, target_b);
	c.half = half(stack_a);
	c.costa = 0;
	current = stack_a;
	while (current != NULL)
	{
		if (current->target == c.target_a)
		{
			if (c.costa < c.half)
				return (c.costa);
			else
				return (c.len_stack - c.costa);
		}
		c.costa++;
		current = current->next;
	}
	return (c.costa);
}

int	cost_target(t_list *a, t_list *b, int len)
{
	t_cost	c;

    c.target_b = 0;
	c.min_cost = INT_MAX;
	c.costa = costa(a, b->target);
	c.costb = costb(b, b->target, len);
	while (b != NULL)
	{
        c.total_cost = c.costa + c.costb;
        if (c.min_cost > c.total_cost)
        {
            c.min_cost = c.total_cost;
            c.target_b = b->target;
			c.content = *b->content;
        }
        b = b->next;
    }
	/* ft_printf("Target b: %d, Content: %d\n", c.target_b, c.content); */
    return (c.target_b);
}
