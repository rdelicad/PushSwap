/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_reverses_nodes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:36:07 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/17 21:01:21 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	reverse_reverse(t_list **stack_a, t_list **stack_b, int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (a > b)
		rra_mayor_b(stack_a, stack_b, a, b);
	else if (a < b)
		rra_minor_b(stack_a, stack_b, a, b);
	else
		rrr_ab(stack_a, stack_b, a);
}

void	rra_mayor_b(t_list **stack_a, t_list **stack_b, int a, int b)
{
	while (a > 0)
	{
		reverse_r(stack_a, stack_b);
		a--;
	}
	while (b > 0)
	{
		reverse_b(stack_b);
		b--;
	}
}

void	rra_minor_b(t_list **stack_a, t_list **stack_b, int a, int b)
{
	while (a > 0)
	{
		reverse_r(stack_a, stack_b);
		a--;
	}
	while (b > 0)
	{
		reverse_a(stack_a);
		b--;
	}
}

void	rrr_ab(t_list **stack_a, t_list **stack_b, int b)
{
	while (b > 0)
	{
		reverse_r(stack_a, stack_b);
		b--;
	}
}
