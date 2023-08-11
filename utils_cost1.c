/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:54:02 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/11 22:47:08 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void    get_cost_total(t_list *stack_a, t_list *stack_b)
{
    t_cost  c;

    while (stack_b != NULL)
    {
        if (stack_a->costa > 0 && stack_b->costb > 0)
        {
            if (stack_a->costa > stack_b->costb)
                c.total_cost = stack_a->costa;
            else
                c.total_cost = stack_b->costb;
        }
        else if (stack_a->costa < 0 && stack_b->costb < 0)
        {
            if (stack_a->costa < stack_b->costb)
                c.total_cost = stack_a->costa;
            else
                c.total_cost = stack_b->costb;
        }
        else
            c.total_cost = abs(stack_a->costa) + abs(stack_b->costb);
        stack_b->cost_total = c.total_cost;
        stack_b = stack_b->next;
    }
}

int get_min_cost(t_list *stack_a, t_list *stack_b)
{
    t_cost  c;
    t_list  *b;

    b = stack_b;
	costb(b);
	while (b != NULL)
	{
		c.costa = costa(stack_a, b->target);
        b->costa = c.costa;
		b = b->next;
	}
    get_cost_total(stack_a, stack_b);
    c.min_cost = INT_MAX;
    while (stack_b != NULL)
    {
        if (c.min_cost < stack_b->cost_total)
            c.min_cost = stack_b->cost_total;
        c.target_b = stack_b->target;
        stack_b = stack_b->next;
    }
    return (c.target_b);
}
