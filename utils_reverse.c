/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:00:37 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/17 21:00:13 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	reverse_stack(t_list **stack_head)
{
	t_list	*tail;
	t_list	*head;

	if (*stack_head == NULL || (*stack_head)->next == NULL)
		return ;
	tail = *stack_head;
	while (tail->next != NULL)
	{
		head = tail;
		tail = tail->next;
	}
	head->next = NULL;
	tail->next = *stack_head;
	*stack_head = tail;
}

void	reverse_a(t_list **stack_a)
{
	reverse_stack(stack_a);
	ft_printf("rra\n");
}

void	reverse_b(t_list **stack_b)
{
	reverse_stack(stack_b);
	ft_printf("rrb\n");
}

void	reverse_r(t_list **stack_a, t_list **stack_b)
{
	reverse_stack(stack_a);
	reverse_stack(stack_b);
	ft_printf("rrr\n");
}
