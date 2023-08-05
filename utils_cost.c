/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:25:33 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/05 22:43:45 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int costb(t_list *stack_b, int target, int len)
{
    t_list  *current;
    int     num;
    int     j;

    len = stack_len(stack_b);
    j = half(stack_b);
    num = 0;
    current = stack_b;
    while (current != NULL)
    {
        if (current->target == target)
        {
            if (num <= j)
                return (num);
            else
                return (len - num - 1);
        }
        num++;
    }
    return (num);
}

int	search_target_a(t_list *stack_a, int target_b)
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
		dist = distance(current->target, target_b);
		if (dist < min_distance)
		{
			min_distance = dist;
			target_a = current->target;
		}
		current->distance = dist;
		current = current->next;
	}
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
	int		i;
	int		j;
	int		target_a;
	int		len_stack;

	len_stack = stack_len(stack_a);
	target_a = search_target_a(stack_a, target_b);
	j = half(stack_a);
	i = 0;
	current = stack_a;
	while (current != NULL)
	{
		if (current->target == target_a)
		{
			if (i < j)
				return (i);
			else
				return (len_stack - i);
		}
		i++;
		current = current->next;
	}
	return (i);
}



int	cost_target(t_list *a, t_list *b, int len)
{
	t_cost	cost;
	int content;

    cost.target_b = 0;
	cost.min_cost = INT_MAX;
	cost.cost_a = costa(a, b->target);
	cost.cost_b = costb(b, b->target, len);
	while (b != NULL)
	{
        cost.total_cost = cost.cost_a + cost.cost_b + b->distance;
        if (cost.min_cost > cost.total_cost)
        {
            cost.min_cost = cost.total_cost;
            cost.target_b = b->target;
			content = *b->content;
        }
        b = b->next;
    }
	ft_printf("TARGET: %d, Content: %d\n", cost.target_b, content);
    return (cost.target_b);
}
