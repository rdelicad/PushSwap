/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_towers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:30:50 by lxuxer            #+#    #+#             */
/*   Updated: 2023/08/05 22:43:31 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int half(t_list *stack)
{
    int half;

    if ((stack_len(stack) % 2) == 0)
        half = stack_len(stack) / 2;
    else if ((stack_len(stack) % 2) != 0)
        half = stack_len(stack) / 2 + 1;
    return (half);
}

int	median(int *argsi, int len)
{
	int	*copy;
	int	medi;
    int i;
    int j;

    copy = copy_argsi(argsi, len);
    i = 0;
    while (i < len - 1)
    {
        j = i + 1;
        while (j < len)
        {
            if (copy[i] > copy [j])
                ft_swap(&copy[i], &copy[j]);
            j++;
        }
        i++;
    }
	medi = copy[i / 2];
	free(copy);
	return (medi);
}

int *copy_argsi(int *argsi, int len)
{
    int *copy;
    int i;

    copy = malloc(sizeof(int) * (len + 1));
    if (!copy)
    {
        free(copy);
        return (NULL);
    }
    i = 0;
    while (i < len)
    {
		copy[i] = argsi[i];
        i++;
    }
	copy[len] = '\0';
    return (copy);
}

// void    move_stack_a(t_list **stack_a, int target)
// {
//     while (stack_a)
//     {
//         if ((*stack_a)->target > target)
//         {
//             if ((*stack_a)->target > half(*stack_a))
//                 rotate_stack(stack_a);
//             else
//                 reverse_stack(stack_a);
//         }
//     }
// }
