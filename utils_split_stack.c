/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:04:57 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/16 21:39:19 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void    ft_split_stack(t_list **a, t_list **b)
{
    t_list	*curr;
	int		max_t;
	int		x;

	curr = *a;
    max_t = INT_MIN;
    while (curr != NULL)
    {
        if (curr->target > max_t)
            max_t = curr->target;
        curr = curr->next;
    }
    x = max_t / 3;
    curr = *a;
	while (curr != NULL)
	{
		if (curr->target < x)
			ft_move1(a, b, curr->target);
		else if (curr->target > x && curr->target < x * 2)
			ft_move2(a, b, curr->target);
		else if (curr->target < max_t)
			ft_move3(a, b, curr->target);
		curr = curr->next;
	}
    ft_move_end(a, b);
}

void    ft_move1(t_list **a, t_list **b, int t)
{
    while (*a != NULL)
    {
        if ((*a)->target == t)
        {
            (*a)->block = 1;
            push_a(b, a);
        }
        if ((*b)->block == 1 && (*b)->next->block == 2)
        {
            rotate_b(b);
            break;
        }
        (*a) = (*a)->next;
    }
}

void    ft_move2(t_list **a, t_list **b, int t)
{
    while (*a != NULL)
    {
        if ((*a)->target == t)
        {
            (*a)->block = 2;
            push_a(b, a);
            break;
        }
        (*a) = (*a)->next;
    }
}

void    ft_move3(t_list **a, t_list **b, int t)
{
    (void)b;
    while (*a != NULL)
    {
        if ((*a)->target == t)
        {
            (*a)->block = 3;
            rotate_a(a);
        }
        (*a) = (*a)->next;
    }
}

void    ft_move_end(t_list **a, t_list **b)
{
    int len;
    int i;

    len = stack_len(*a);
    i = 0;
    while (i < len - 3)
    {
        push_b(a, b);
        i++;
        (*a) = (*a)->next;
    }
}