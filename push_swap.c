/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:28:49 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/18 15:53:45 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int	characters(char **args)
{
	int	i;
	int	j;

	i = 0;
	if (args[i] == NULL)
		return (1);
	while (args[i] != NULL)
	{
		j = 0;
		if (args[i][j] == '\0' && (args[i + 1] != NULL || args[i + 1] == NULL))
			return (1);
		while (args[i][j] != '\0')
		{
			if (j == 0 && (args[i][0] == '-' || args[i][0] == '+'))
				j++;
			if (!(ft_isdigit(args[i][j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	duplicates(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i] != NULL)
	{
		j = i + 1;
		if (ft_atol(args[i]) > INT_MAX || ft_atol(args[i]) < INT_MIN)
			return (1);
		while (args[j] != NULL)
		{
			if (ft_atol(args[i]) == ft_atol(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**valid_args(int ac, char **av)
{
	char	**args;

	args = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else if (ac > 2)
		args = av + 1;
	if (characters(args))
	{
		write (2, "Error\n", 6);
		return (NULL);
	}
	else if (duplicates(args))
	{
		write (2, "Error\n", 6);
		return (NULL);
	}
	return (args);
}

t_struct	convert_int_args(char **args)
{
	t_struct	result;
	int			*argsi;
	int			len;
	int			i;

	len = 0;
	while (args[len] != NULL)
		len++;
	argsi = (int *)malloc(sizeof(int) * (len + 1));
	if (!argsi)
	{
		result.argsi = (NULL);
		result.len = 0;
		return (result);
	}
	i = 0;
	len = 0;
	while (args[i] != NULL)
		argsi[i++] = ft_atoi(args[len++]);
	argsi[i] = '\0';
	result.argsi = argsi;
	result.len = i;
	return (result);
}

int	main(int ac, char **av)
{
	char		**args;
	t_list		*stack_a;
	t_list		*stack_b;
	t_struct	result;

	stack_b = NULL;
	args = valid_args(ac, av);
	if (!args)
		return (0);
	result = convert_int_args(args);
	stack_a = create_stack_a(result.argsi, result.len);
	algorithm(&stack_a, &stack_b, result);
	free_memory_split(ac, result.len, args);
	free_memory_stacks(result.argsi, stack_a, stack_b);
	return (0);
}
