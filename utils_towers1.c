/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_towers1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:25:58 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/09 15:32:12 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void    move_a(t_list **stack_a, int target_b, t_move m)
{
    if (target_b < m.target_a)
    {
        b_minor_a(stack_a, target_b, m);
    }
    else
    {
        b_mayor_a(stack_a, target_b, m);
    }
    
}

void    b_minor_a(t_list **stack_a, int target_b, t_move m)
{
    if (target_b < m.target_a)
    {
        if (m.posit >= half(*stack_a))
        {
            while (m.posit < m.len - 1)
            {
                reverse_a(stack_a);
                m.posit++;
            }
            if (m.posit == m.len - 1)
                reverse_a(stack_a);
        }
        else
        {
            while (m.posit > 0)
            {
                rotate_a(stack_a);
                m.posit--;
            }
        }
    }
}

void    b_mayor_a(t_list **stack_a, int target_b, t_move m)
{
    if (target_b > m.target_a)
    {
        if (m.posit < half(*stack_a))
        {
            while (m.posit > 0)
            {
                rotate_a(stack_a);
                m.posit--;
            }
            if (m.posit == 0)
                rotate_a(stack_a);
        }
        else
        {
            while (m.posit < m.len - 1)
            {
                reverse_a(stack_a);
                m.posit++;
            }
        }
    }
}
