/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:11:26 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/01 20:12:48 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

//intercambia los primeros elementos encima de stack A
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

t_list	*print_movements(t_list *stack_a, t_list *stack_b)
{
	const t_list	*tmp_a;
	const t_list	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	if (stack_a == NULL)
		ft_printf("Pila vacia\n");
	else
	{
		ft_printf("Pila A: \n");
		while (tmp_a != NULL)
		{
			ft_printf("%i ", *(int *)(tmp_a->content));
			tmp_a = tmp_a->next;
		}
	}
	ft_printf("\n\n");
	if (stack_b == NULL)
		ft_printf("Pila vacia");
	else
	{
		ft_printf("Pila B: \n");
		while (tmp_b != NULL)
		{
			ft_printf("%i ", *(int *)(tmp_b->content));
			tmp_b = tmp_b->next;
		}
	}
	ft_printf("\n");
	ft_printf("-------------------------------\n\n");
	return (0);
}
