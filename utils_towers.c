/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_towers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:30:50 by lxuxer            #+#    #+#             */
/*   Updated: 2023/08/03 20:09:09 by rdelicad         ###   ########.fr       */
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

    copy = copy_argsi(argsi, len);
	if (len % 2 == 1)
		medi = copy[len / 2];
	else
		medi = (copy[len / 2 - 1] + copy[len / 2] / 2);
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
