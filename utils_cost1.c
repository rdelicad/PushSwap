/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:54:02 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/10 23:03:04 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int get_cost_targets(t_list *stack_a, t_list *stack_b, int len)
{
    t_list  *a;
    t_list  *b;

    a = stack_a;
    b = stack_b;
    assig_cost_nodes(a, b, len);
    while (b != NULL)
    {
        
    }
    
}