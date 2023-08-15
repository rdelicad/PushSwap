/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotates_nodes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:34:33 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/15 14:08:00 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void    reverse_rotate(t_list **stack_a, t_list **stack_b, int a, int b)
{
    if (a > b)
		ra_mayor_b(stack_a, stack_b, a, b);
    else if (a < b)
        ra_minor_b(stack_a, stack_b, a, b);
    else
        rr_ab(stack_a, stack_b, b);
}

void    ra_mayor_b(t_list **stack_a, t_list **stack_b, int a, int b)
{
    while (a > 0)
    {
        rotate_r(stack_a, stack_b);
        a--;
    }
    while (b > 0)
    {
        rotate_a(stack_a);
        b--;
    }
    print_movements(*stack_a, *stack_b);
}

void    ra_minor_b(t_list **stack_a, t_list **stack_b, int a, int b)
{
    while (a > 0)
    {
        rotate_r(stack_a, stack_b);
        a--;
    }
    while (b > 0)
    {
        rotate_b(stack_b);
        b--;
    }
    print_movements(*stack_a, *stack_b);
}

void    rr_ab(t_list **stack_a, t_list **stack_b, int b)
{
    while (b > 0)
    {
        rotate_r(stack_a, stack_b);
        b--;
    }
}