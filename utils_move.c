/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:03:09 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/14 21:34:03 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void    move(t_list **stack_a, t_list **stack_b, int a, int b)
{
        if (a > 0 && b > 0)
            reverse_rotate(stack_a, stack_b, a, b);
        else if (a < 0 && b < 0)
            reverse_reverse(stack_a, stack_b, a, b);
        else if (a == 0 && b == 0)
            push_a(stack_b, stack_a);
        else
        {
            if (b == 0)
                move_node_a(stack_a, stack_b, a);
            else if (a == 0)
            {
                move_node_b(stack_a, stack_b, b);
                push_a(stack_b, stack_a);
                print_movements(*stack_a, *stack_b);
            }
            else
            {
                move_node_a(stack_a, stack_b, a);
                move_node_b(stack_a, stack_b, b);
                push_a(stack_b, stack_a);
                print_movements(*stack_a, *stack_b);
            }
        }
}

