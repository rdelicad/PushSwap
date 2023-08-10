/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:25:33 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/10 20:30:00 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	costb(t_list *stack_b, int len)
{
    t_list  *current;
	t_cost	c;

    len = stack_len(stack_b);
    c.half = half(stack_b);
    current = stack_b;
	c.i = 0;
    while (c.i < len)
    {
		if (current->costb >= c.half)
			current->costb = c.i;
		else
			current->costb = c.i - len - 1;
    }
}

void	costa(t_list *stack_a, int target_b)
{
	t_list	*current;
	t_cost	c;

	c.len_stack = stack_len(stack_a);
	c.target_a = search_upper_a(stack_a, target_b);
	c.half = half(stack_a);
	c.costa = 0;
	current = stack_a;
	while (current != NULL)
	{
		if (current->target == c.target_a)
		{
			if (c.costa < c.half)
				current->costa = c.costa;
			else
				current->costa = c.costa - c.len_stack -1;
		}
		c.costa++;
		current = current->next;
	}
}

int	search_upper_a(t_list *stack_a, int target_b)
{
	t_list		*current;
	t_search	s;

	s.target_a = 0;
	s.min = INT_MAX;
	current = stack_a;
	while (current != NULL)
	{
		s.dist = current->target - target_b;
		if (s.dist <= s.min && s.dist > 0)
		{
			s.min = s.dist;
			s.target_a = current->target;
		}
		current = current->next;
	}
	if (s.target_a == 0)
		search_lower_a(stack_a, target_b);
	/* ft_printf ("target a: %d\n", target_a); */
	return (s.target_a);
}

int	search_lower_a(t_list *stack_a, int target_b)
{
    t_list		*current;
	t_search	s;

	s.target_a = 0;
	s.min = INT_MAX;
	current = stack_a;
	while (current != NULL)
	{
		s.dist = current->target - target_b;
		if (s.dist <= s.min)
		{
			s.lower = s.dist;
			s.target_a = current->target;
		}
		current = current->next;
	}
	return (s.target_a);
}


int	cost_target(t_list *stack_a, t_list *stack_b, int len)
{
	t_list	*a;
	t_list	*b;
	t_cost	c;

    c.target_b = 0;
	c.min_cost = len;
	b = stack_b;
	a = stack_a;
	while (b != NULL)
	{
        c.total_cost = a->costa + b->costb;
        b = b->next;
    }
	/* ft_printf("Target b: %d, Content: %d\n", c.target_b, c.content); */
    return (c.target_b);
}
