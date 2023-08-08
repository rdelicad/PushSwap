/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:11:26 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/08 14:10:10 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_list	*print_movements(t_list *stack_a, t_list *stack_b)
{
	const t_list	*tmp_a;
	const t_list	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	if (1 == 0)
	{
		if (stack_a == NULL)
			ft_printf("Pila vacia\n");
		else
		{
			ft_printf("\nPila A: \n");
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
	}
	return (0);
		
}
