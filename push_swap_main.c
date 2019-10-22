/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:08:29 by bmarks            #+#    #+#             */
/*   Updated: 2019/07/22 15:30:23 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libps.h"

static int	submain(int argc, char **argv)
{
	char	*stack_a[argc - 1];
	char	*stack_b[argc - 1];
	int		size[2];
	int		n;

	stack_init(stack_a, stack_b, argv, argc - 2);
	size[0] = (int)sizeof(stack_a) / 8;
	size[1] = 0;
	n = core_logic(stack_a, stack_b, size);
	while (n)
		n = core_logic(stack_a, stack_b, size);
	return (0);
}

int			main(int argc, char **argv)
{
	char	*list[100000];
	int		num;

	num = 0;
	if (argc > 1)
	{
		arg_format(argc - 1, &argv[1], &num, list);
		submain(num + 1, list);
	}
	return (0);
}
