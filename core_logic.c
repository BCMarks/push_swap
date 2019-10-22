/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:32:00 by bmarks            #+#    #+#             */
/*   Updated: 2019/07/22 15:16:15 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libps.h"

void		eksaqte(int num, char **stack_a, char **stack_b, int size[])
{
	const char	*cmds[] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	ft_putendl(cmds[num]);
	operations((char *)cmds[num], stack_a, stack_b, size);
}

int			num_order(int size, char **stack)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (ft_atoi(stack[i]) > ft_atoi(stack[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int			core_logic(char **stack_a, char **stack_b, int size[])
{
	int		solved;

	solved = num_order(size[0], stack_a);
	if (solved == 0)
	{
		if (size[0] == 2)
			eksaqte(0, stack_a, stack_b, size);
		else if (size[0] == 3)
			solve3(stack_a, stack_b, size);
		else if (size[0] <= SORT_SIZE)
			small_solve(stack_a, stack_b, size);
		else if (size[0] <= 240)
			comparitive(stack_a, stack_b, size);
		else
			comparitive2(stack_a, stack_b, size);
		return (1);
	}
	return (0);
}
