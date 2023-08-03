/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:22:22 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/01 18:22:10 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_list	*create_stack_a(int *argsi, int len)
{
	t_list	*stack_a;

	stack_a = create_nodes(argsi, len);
	assign_target(&stack_a);
	return (stack_a);
}

t_list	*create_nodes(int *argsi, int len)
{
	t_list	*stack_a;
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < len)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(&argsi[i]));
		i++;
	}
	return (stack_a);
}
int	get_position(t_list **stack_a, int node_value)
{
	t_list	*current;
	int		target;

	target = 0;
	current = *stack_a;
	while (current != NULL)
	{
		if (*current->content <= node_value)
			target++;
		current = current->next;
	}
	return (target);
}

void	assign_target(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	while (current != NULL)
	{
		current->target = get_position(stack_a, *current->content);
		current = current->next;
	}
}

int	median(int *argsi, int len)
{
	int	*copy_argsi;
	int	i;
	int	j;
	int	medi;

	copy_argsi = malloc(sizeof(int) * (len + 1));
	ft_memcpy(copy_argsi, argsi, len);
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (*(copy_argsi + i) < *(copy_argsi + j))
				ft_swap(copy_argsi + i, copy_argsi + j);
			j++;
		}
		i++;
	}
	medi = copy_argsi[len / 2];
	free(copy_argsi);
	return (medi);
}
