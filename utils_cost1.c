/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:54:02 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/18 14:57:28 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	get_cost_total(t_list *stack_b)
{
	t_cost	c;

	while (stack_b != NULL)
	{
		if (stack_b->costa > 0 && stack_b->costb > 0)
		{
			if (stack_b->costa > stack_b->costb)
				c.total_cost = stack_b->costa;
			else
				c.total_cost = stack_b->costb;
		}
		else if (stack_b->costa < 0 && stack_b->costb < 0)
		{
			if (stack_b->costa < stack_b->costb)
				c.total_cost = stack_b->costa;
			else
				c.total_cost = stack_b->costb;
		}
		else if (stack_b->costa == 0 && stack_b->costb == 0)
			c.total_cost = 0;
		else
			c.total_cost = abs(stack_b->costa) + abs(stack_b->costb);
		stack_b->cost_total = abs(c.total_cost);
		stack_b = stack_b->next;
	}
}

int	get_min_cost(t_list *stack_a, t_list *stack_b)
{
	t_cost	c;
	t_list	*b;

	b = stack_b;
	costb(b);
	while (b != NULL)
	{
		c.costa = costa(stack_a, b->target);
		b->costa = c.costa;
		b = b->next;
	}
	get_cost_total(stack_b);
	c.min_cost = INT_MAX;
	b = stack_b;
	while (b != NULL)
	{
		if (abs(c.min_cost) > b->cost_total)
		{
			c.min_cost = b->cost_total;
			c.target_b = b->target;
		}
		b = b->next;
	}
	return (c.target_b);
}

int	get_target_index(t_list *stack, int target)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->target == target)
			return (i);
		stack = stack->next;
		i++;
	}
	return (0);
}
