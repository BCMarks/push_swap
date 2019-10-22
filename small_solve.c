/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:52:37 by bmarks            #+#    #+#             */
/*   Updated: 2019/07/22 15:30:32 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libps.h"

static char	*find_largest(char **stack, int size)
{
	char	*l;
	int		i;

	i = 0;
	l = stack[i];
	while (i++ < size - 1)
		if (ft_atoi(stack[i]) > ft_atoi(l))
			l = stack[i];
	return (l);
}

static char	*find_smallest(char **stack, int size)
{
	char	*l;
	int		i;

	i = 0;
	l = stack[i];
	while (i++ < size - 1)
		if (ft_atoi(stack[i]) < ft_atoi(l))
			l = stack[i];
	return (l);
}

void		solve3(char **stack_a, char **stack_b, int size[])
{
	char	*l;

	l = find_largest(stack_a, size[0]);
	while (!num_order(size[0], stack_a))
	{
		if (ft_atoi(stack_a[0]) > ft_atoi(stack_a[1]) &&
				ft_atoi(stack_a[1]) > ft_atoi(stack_a[2]))
			eksaqte(0, stack_a, stack_b, size);
		else if (ft_atoi(stack_a[1]) > ft_atoi(stack_a[2]) &&
				ft_atoi(stack_a[2]) > ft_atoi(stack_a[0]))
			eksaqte(0, stack_a, stack_b, size);
		else if (ft_atoi(stack_a[0]) == ft_atoi(l))
			eksaqte(5, stack_a, stack_b, size);
		else if (ft_atoi(stack_a[1]) == ft_atoi(l))
			eksaqte(8, stack_a, stack_b, size);
		else if (ft_atoi(stack_a[2]) == ft_atoi(l))
			eksaqte(0, stack_a, stack_b, size);
	}
}

static void	b_return(char **stack_a, char **stack_b, int size[])
{
	int	i;

	i = 0;
	if ((ft_atoi(stack_b[0]) > ft_atoi(find_largest(stack_a, size[0]))) ||
		(ft_atoi(stack_b[0]) < ft_atoi(find_smallest(stack_a, size[0]))))
		end_bot(stack_a, stack_b, size);
	else
	{
		while (i++ < size[0] - 1)
			if ((ft_atoi(stack_b[0]) > ft_atoi(stack_a[i - 1])) &&
					(ft_atoi(stack_b[0]) < ft_atoi(stack_a[i])))
				break ;
		if (i != size[0])
		{
			if (i <= size[0] / 2)
				while (i-- > 0)
					eksaqte(5, stack_a, stack_b, size);
			else
				while (size[0] - i++ > 0)
					eksaqte(8, stack_a, stack_b, size);
		}
	}
	eksaqte(3, stack_a, stack_b, size);
}

void		small_solve(char **stack_a, char **stack_b, int size[])
{
	while (size[0] > 3)
		eksaqte(4, stack_a, stack_b, size);
	solve3(stack_a, stack_b, size);
	while (size[1])
		b_return(stack_a, stack_b, size);
	end_bot(stack_a, stack_b, size);
}
