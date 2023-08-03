/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:25:33 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/03 15:57:44 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int costb(t_list *stack_b, int target)
{
    t_list  *current;
    int     i;
    int     j;
    int     len;

    len = stack_len(stack_b);
    j = half(stack_b);
    i = 0;
    current = stack_b;
    while (current != NULL)
    {
        if (current->target == target)
        {
            if (i <= j)
                return (i);
            else
                return (i - len - 1);
        }
        i++;
    }
    return (i);
}

int	costa(t_list *stack_a, int target_b, int len)
{
	t_list	*current;
	int		i;
	int		j;
	int		target_a;
	int		len_stack;

	len_stack = stack_len(stack_a);
	target_a = search_target_a(stack_a, target_b, len);
	j = half(stack_a);
	i = 0;
	current = stack_a;
	while (current != NULL)
	{
		if (current->target == target_a)
		{
			if (i <= j)
				return (i);
			else
				return (i - len_stack);
		}
		i++;
		current = current->next;
	}
	return (i);
}

int	search_target_a(t_list *stack_a, int target_b, int len)
{
	t_list	*current;
	int		min_distance;
	int		target_a;
	int		dist;

	target_a = 0;
	min_distance = INT_MAX;
	current = stack_a;
	while (current != NULL)
	{
		dist = distance(current->target, target_b, len);
		if (dist < min_distance)
		{
			min_distance = dist;
			target_a = current->target;
		}
		current = current->next;
	}
	return (target_a);
}

int	distance(int a, int b, int len)
{
    int	dist;

	dist = a - b;
	if (dist < 0)
		dist += len;
	return (dist);
}

int	cost_target(t_list *a, t_list *b, int len)
{
	int min_cost;
    int target;    
	int total_cost;

    target = 0;
	min_cost = INT_MAX;
	while (b != NULL)
	{
        total_cost = costa(a, b->target, len) + costb(b, b->target);
        if (min_cost > total_cost)
        {
            min_cost = total_cost;
            target = b->target;
        }
        b = b->next;
    }
    return (target);
}