/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:32:32 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/17 21:07:44 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	swap_stack(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = (*stack)->next;
	if (ft_lstsize(*stack) <= 1)
		return ;
	else
	{
		first->next = second->next;
		second->next = first;
		*stack = second;
	}
}

void	swap_a(t_list **stack_a)
{
	swap_stack(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_list **stack_b)
{
	swap_stack(stack_b);
	ft_printf("sb\n");
}

void	swap_s(t_list **stack_a, t_list **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	ft_printf("ss\n");
}
