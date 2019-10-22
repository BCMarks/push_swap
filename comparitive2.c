/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparitive2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:05:54 by bmarks            #+#    #+#             */
/*   Updated: 2019/07/22 15:30:07 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libps.h"

static int	in_zseg2(char **stack_a, char **z_stack, int seg[], int size)
{
	int	i;
	int	j;

	j = 0;
	i = size;
	while (--i > -1)
	{
		while (ft_atoi(stack_a[i]) != ft_atoi(z_stack[seg[1] + j]) &&
				seg[1] + j < seg[0] - 1)
			j++;
		if (ft_strcmp(stack_a[i], z_stack[seg[1] + j]) == 0)
			break ;
		j = 0;
	}
	return (size - i);
}

static int	in_zseg1(char **stack_a, char **z_stack, int seg[], int size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < size)
	{
		while (ft_atoi(stack_a[i]) != ft_atoi(z_stack[seg[1] + j]) &&
				seg[1] + j < seg[0] - 1)
			j++;
		if (ft_strcmp(stack_a[i], z_stack[seg[1] + j]) == 0)
			break ;
		j = 0;
		i++;
	}
	return (i);
}

static void	seg_sort(char **stack_a, char **stack_b, int size[], char **z_stack)
{
	static int	i[2];
	int			j;
	static int	postop;
	static int	posbot;

	j = 0;
	postop = 0;
	posbot = 0;
	i[1] = i[0];
	if (i[0] + SORT_SIZE2 < size[0])
		i[0] += SORT_SIZE2;
	else
		i[0] = size[0];
	while (j < i[0] - i[1])
	{
		postop = in_zseg1(stack_a, z_stack, i, size[0]);
		posbot = in_zseg2(stack_a, z_stack, i, size[0]);
		postop <= posbot ? big_solve1(stack_a, stack_b, size, postop) :
			big_solve2(stack_a, stack_b, size, posbot);
		j++;
	}
}

void		comparitive2(char **stack_a, char **stack_b, int size[])
{
	static int	iter = -1;
	char		*z_state_a[size[0]];
	char		*z_state_b[size[0]];
	int			z_size[2];

	if (iter++ <= size[0] / SORT_SIZE2)
	{
		stack_init(z_state_a, z_state_b, stack_a, size[0] - 1);
		z_size[0] = size[0];
		z_size[1] = 0;
		brute_solve(z_state_a, z_state_b, z_size);
		seg_sort(stack_a, stack_b, size, z_state_a);
		if (iter < size[0] / SORT_SIZE2)
			end_topa(stack_a, stack_b, size);
		if (iter == size[0] / SORT_SIZE2)
			end_bot(stack_a, stack_b, size);
		while (size[1])
		{
			end_topb(stack_a, stack_b, size);
			eksaqte(3, stack_a, stack_b, size);
		}
		if (iter == size[0] / SORT_SIZE2)
			end_bot(stack_a, stack_b, size);
	}
}
