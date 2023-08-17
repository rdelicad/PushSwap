/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:55:25 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/17 20:59:40 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	push_stack(t_list **stack_init, t_list **stack_end)
{
	t_list	*push;

	if (stack_init != NULL)
	{
		push = *stack_init;
		*stack_init = (*stack_init)->next;
		push->next = *stack_end;
		*stack_end = push;
	}
	else
		return ;
}

void	push_a(t_list **stack_b, t_list **stack_a)
{
	push_stack(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	push_stack(stack_a, stack_b);
	ft_printf("pb\n");
}
