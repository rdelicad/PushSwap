/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:25:33 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/15 21:31:44 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	costb(t_list *stack_b)
{
    t_list  *current;
	t_cost	c;
	int		i;

    c.len_stack = stack_len(stack_b);
    c.half = half(stack_b);
    current = stack_b;
	i = 0;
    while (i < c.len_stack)
    {
		if (i < c.half)
			current->costb = i;
		else
			current->costb = i - c.len_stack;
		i++;
		current = current->next;
    }
}

int	costa(t_list *stack_a, int target_b)
{
	t_list	*current;
	t_cost	c;
	int		i;

	c.len_stack = stack_len(stack_a);
	c.target_a = search_upper_a(stack_a, target_b);
	c.half = half(stack_a);
	i = 0;
	current = stack_a;
	while (current != NULL)
	{
		if (current->target == c.target_a)
		{
			if (i < c.half)
				c.costa = i;
			else
				c.costa = i- c.len_stack;
			break;
		}
		i++;
		current = current->next;
	}
	return (c.costa);
}

int	search_upper_a(t_list *stack_a, int target_b)
{
	t_list *current;
    t_search s;

    s.target_a = 0;
    s.min_upper = INT_MAX;

    current = stack_a;
    while (current != NULL) {
        s.diff = current->target - target_b;
        if (s.diff > 0 && s.diff <= s.min_upper) 
		{
            s.min_upper = s.diff;
            s.target_a = current->target;
        } 
        current = current->next;
    }
	if (s.target_a == 0)
		s.target_a = search_lower_a(stack_a, target_b);
	return (s.target_a);
}

int	search_lower_a(t_list *stack_a, int target_b)
{
    t_list		*current;
	t_search	s;

	s.target_a = 0;
	s.min_lower = INT_MAX;
	current = stack_a;
	while (current != NULL)
	{
		s.diff = (current->target - target_b);
		if (s.diff < s.min_lower)
		{
			s.min_lower = s.diff;
			s.target_a = current->target;
		}
		current = current->next;
	}
	return (s.target_a);
}


void	assig_cost_nodes(t_list *stack_a, t_list *stack_b)
{
	t_list	*a;
	t_list	*b;

	a = stack_a;
	b = stack_b;
	costb(b);
	while (b != NULL)
	{
		costa(a, b->target);
		b = b->next;
	}
}
