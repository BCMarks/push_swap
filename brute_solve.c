/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:12:25 by bmarks            #+#    #+#             */
/*   Updated: 2019/07/08 12:24:36 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libps.h"

static void	find_smol(char **stack_a, char **stack_b, int size[])
{
	int	i;
	int	low;

	i = -1;
	low = 0;
	while (++i < size[0])
		low = (ft_atoi(stack_a[low]) < ft_atoi(stack_a[i])) ?
			low : i;
	(low == 0) ? operations("pb", stack_a, stack_b, size) :
				operations("ra", stack_a, stack_b, size);
}

void		brute_solve(char **stack_a, char **stack_b, int size[])
{
	while (size[0] > 1)
		find_smol(stack_a, stack_b, size);
	while (size[1])
		operations("pa", stack_a, stack_b, size);
}
