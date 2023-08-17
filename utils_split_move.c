/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:04:57 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/17 21:04:56 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_move1(t_list **a, t_list **b)
{
	(*a)->block = 1;
	push_b(a, b);
	print_movements(*a, *b);
}

void	ft_move2(t_list **a, t_list **b)
{
	(*a)->block = 2;
	push_b(a, b);
	print_movements(*a, *b);
}

void	ft_move3(t_list **a, t_list **b)
{
	(*a)->block = 3;
	push_b(a, b);
	print_movements(*a, *b);
	if ((*b)->next != NULL)
	{
		if ((*b)->block == 3 && (*b)->next->block == 2)
		{
			rotate_b(b);
			print_movements(*a, *b);
		}
	}
}

void	ft_move4(t_list **a, t_list **b)
{
	(*a)->block = 4;
	push_b(a, b);
	print_movements(*a, *b);
	if ((*b)->next != NULL)
	{
		if ((*b)->block == 4 && ((*b)->next->block == 1 || (*b)->next->block == 3))
		{
			rotate_b(b);
			print_movements(*a, *b);
		}
	}
}

void	ft_move_end(t_list **a, t_list **b)
{
	t_list	*curr;
	int		len;
	int		i;

	curr = *a;
	len = stack_len(*a);
	i = 0;
	while (curr != NULL && i < len - 3)
	{
		push_b(a, b);
		i++;
		curr = curr->next;
		print_movements(*a, *b);
	}
}
