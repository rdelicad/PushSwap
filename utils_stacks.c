/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:10:25 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/03 21:33:29 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	free_memory_split(int ac, int i, char **args)
{
	if (ac == 2)
	{
		while (i >= 0)
			free(args[i--]);
		free(args);
	}
}

void	free_memory_stacks(int *argsi, t_list *stack_a, t_list *stack_b)
{
	t_list	*aux;

	while (stack_a)
	{
		aux = stack_a->next;
		free(stack_a);
		stack_a = aux;
	}
	while (stack_b)
	{
		aux = stack_b->next;
		free(stack_b);
		stack_b = aux;
	}
	free(argsi);
}

t_list	*end_stack(t_list *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	is_sorted(t_list *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (*stack->content < *stack->next->content)
		{
			stack = stack->next;
		}
		else
			return (0);
	}
	return (1);
}

int	stack_len(t_list *stack)
{
	t_list	*current;
	int		len;

	len = 0;
	current = stack;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	return (len);
}
