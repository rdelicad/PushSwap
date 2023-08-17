/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:42:01 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/17 21:01:50 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rotate_stack(t_list **stack_head)
{
	t_list	*tail;
	t_list	*head;

	if (*stack_head == NULL || (*stack_head)->next == NULL)
		return ;
	tail = *stack_head;
	while (tail->next != NULL)
		tail = tail->next;
	head = *stack_head;
	*stack_head = (*stack_head)->next;
	head->next = NULL;
	tail->next = head;
}

void	rotate_a(t_list **stack_a)
{
	rotate_stack(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	rotate_stack(stack_b);
	ft_printf("rb\n");
}

void	rotate_r(t_list **stack_a, t_list **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	ft_printf("rr\n");
}
