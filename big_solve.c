/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:43:18 by bmarks            #+#    #+#             */
/*   Updated: 2019/07/22 15:29:18 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libps.h"

void	end_bot(char **stack_a, char **stack_b, int size[])
{
	int		i;
	int		j;
	char	*end;

	i = 0;
	j = 0;
	end = stack_a[i];
	while (i < size[0] - 1)
	{
		i++;
		if (ft_atoi(stack_a[i]) > ft_atoi(end))
		{
			j = i;
			end = stack_a[i];
		}
	}
	j++;
	if (j <= size[0] / 2)
		while (j--)
			eksaqte(5, stack_a, stack_b, size);
	else
		while (size[0] - j++)
			eksaqte(8, stack_a, stack_b, size);
}

void	end_topa(char **stack_a, char **stack_b, int size[])
{
	int		i;
	int		j;
	char	*end;

	i = 0;
	j = 0;
	end = stack_a[i];
	while (i < size[0] - 1)
	{
		i++;
		if (ft_atoi(stack_a[i]) > ft_atoi(end))
		{
			j = i;
			end = stack_a[i];
		}
	}
	if (j <= size[0] / 2)
		while (j--)
			eksaqte(5, stack_a, stack_b, size);
	else
		while (size[0] - j++)
			eksaqte(8, stack_a, stack_b, size);
}

void	end_topb(char **stack_a, char **stack_b, int size[])
{
	int		i;
	int		j;
	char	*end;

	i = 0;
	j = 0;
	end = stack_b[i];
	while (i < size[1] - 1)
	{
		i++;
		if (ft_atoi(stack_b[i]) > ft_atoi(end))
		{
			j = i;
			end = stack_b[i];
		}
	}
	if (j <= size[1] / 2)
		while (j--)
			eksaqte(6, stack_a, stack_b, size);
	else
		while (size[1] - j++)
			eksaqte(9, stack_a, stack_b, size);
}

void	big_solve2(char **stack_a, char **stack_b, int size[], int n)
{
	while (n)
	{
		eksaqte(8, stack_a, stack_b, size);
		n--;
	}
	eksaqte(4, stack_a, stack_b, size);
}

void	big_solve1(char **stack_a, char **stack_b, int size[], int n)
{
	while (n)
	{
		eksaqte(5, stack_a, stack_b, size);
		n--;
	}
	eksaqte(4, stack_a, stack_b, size);
}
