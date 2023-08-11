/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:54:02 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/11 18:49:10 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int get_cost_targets(t_list *stack_a, t_list *stack_b, int target, int len)
{
    t_cost  c;

    coste total
    assig_cost_nodes(stack_a, stack_b, len);
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
}

int min_cost(t_list *stack_a, t_list *stack_b, int len)
{
    t_cost  c;

	while (b != NULL)
	{
		costa(a, b->target);
		b = b->next;
	}

	costb(a, b->target);


    cost_total_calculate()

    get_min_cost_node()
    c.min_cost = INT_MAX;
    while (stack_b != NULL)
    {
        c.total_cost = get_cost_targets(stack_a, stack_b, stack_b->target, len);
        if (c.min_cost < c.total_cost)
        {
            c.min_cost = c.total_cost;
            c.target_b = stack_b->target;
        }
        stack_b = stack_b->next;
    }
    return (c.target_b);
}
