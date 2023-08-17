/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:30:07 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/17 18:22:33 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void ft_split_stack(t_list **a, t_list **b)
{
    t_list *curr;
    int max_t;
    int x;
    int len;

    len = stack_len(*a);
    curr = *a;
    max_t = INT_MIN;
    while (curr != NULL)
    {
        if (curr->target > max_t)
            max_t = curr->target;
        curr = curr->next;
    }
    x = max_t / 4;
    middle_lower(a, b, x, len);
    middle_upper(a, b, x, max_t);
    //ft_move_end(a, b);
}

void	middle_lower(t_list **a, t_list **b, int x, int len)
{
	int	i;
	int flag;

	i = 0;
    while (i < len)
    {
        flag = 1;
        if ((*a)->target >= x * 2 && (*a)->target <= x * 3)
            ft_move2(a, b);
        else if ((*a)->target > x && (*a)->target < x * 2)
            ft_move3(a, b);
        else 
        {
			rotate_a(a);
            i++;
            flag = 0;
            print_movements(*a, *b);
        }
        if (flag == 1)
            i++;
    }
}

void	middle_upper(t_list **a, t_list **b, int x, int max_t)
{
	int	i;
    int len;
    int top;

    len = stack_len(*a);
	i = 0;
    top = 0;
    while (i < len - 3)
    {
        if ((*a)->target >= x * 3 && (*a)->target <= max_t && top < 3)
        {
            rotate_a(a);
            top++;
        }
        if ((*a)->target >= x * 3 && (*a)->target <= max_t)
            ft_move1(a, b);
        else if ((*a)->target <= x)
            ft_move4(a, b);
        i++;
    }
}

void    algorithm_medium(t_list **a, t_list **b, int medi)
{
    t_tower t;

	t.flag = 0;
	t.top = 0;
	t.i = 0;
	t.len_a = stack_len(*a);
	while (t.i < t.len_a - 3)
	{
		t.len_b = stack_len(*b);
		if (*((*a)->content) > medi && t.top++ < 3)
		{
			rotate_a(a);
			t.flag = 1;
            print_movements(*a, *b);
		}
		else
		{
			push_b(a, b);
			t.i++;
            print_movements(*a, *b);
		}
		if (t.len_b > 1 && *((*b)->content) <= medi && t.flag == 0)
		{
			if (*((*b)->next->content) > medi)
			{
                rotate_b(b);
                print_movements(*a, *b);
            }
		}
		t.flag = 0;
	}
}