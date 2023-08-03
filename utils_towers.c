/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_towers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:30:50 by lxuxer            #+#    #+#             */
/*   Updated: 2023/08/03 11:22:43 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int half(t_list *stack)
{
    int half;

    if ((stack_len(stack) % 2) == 0)
        half = stack_len(stack) / 2;
    else if ((stack_len(stack) % 2) != 0)
        half = stack_len(stack) / 2 + 1;
    return (half);
}

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

int	costa(t_list *stack_a, int target_b)
{
	t_list	*current;
	int		i;
	int		j;
	int		target_a;
	int		len;

	len = stack_len(stack_a);
	target_a = search_target_a(stack_a, target_b);
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
				return (i - len);
		}
		i++;
		current = current->next;
	}
	return (i);
}

int	search_target_a(t_list *stack_a, int target_b)
{
	t_list	*current;
	int		i;

	i = 1;
	current = stack_a;
	while (current != NULL)
	{
		if (current->target == target_b + i)
			return (current->target);
		i++;
	}
	return (0);
}

int	cost_target(t_list *a, t_list *b)
{
	int min_cost;
    // int costb_target;
    // int costa_target;
	int total_cost;

	min_cost = INT_MAX;
	while (b != NULL)
	{
        // costb_target = costb(b, b->target);
        // costa_target = costa(a, b->target);
        total_cost = costa(a, b->target) + costb(b, b->target);
        if (min_cost > total_cost)
            min_cost = total_cost;
        b = b->next;
    }
    return (b->target);
}