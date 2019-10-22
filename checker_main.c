/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 13:06:33 by bmarks            #+#    #+#             */
/*   Updated: 2019/07/22 15:29:47 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libps.h"

static int	main2(int argc, char **argv)
{
	char	*stack_a[argc - 1];
	char	*stack_b[argc - 1];
	char	*cmd;
	int		size[2];

	stack_init(stack_a, stack_b, argv, argc - 2);
	size[0] = (int)sizeof(stack_a) / 8;
	size[1] = 0;
	ft_putendl("\nInitializing stacks...");
	disp_lists(stack_a, stack_b, size[0], size[1]);
	while (get_next_line(0, &cmd))
	{
		operations(cmd, stack_a, stack_b, size);
		ft_putstr("\nExecuting operation: ");
		ft_putendl(cmd);
		disp_lists(stack_a, stack_b, size[0], size[1]);
		free(cmd);
	}
	free(cmd);
	checka(stack_a, stack_b, size[0]);
	return (0);
}

static int	main3(int argc, char **argv)
{
	char	*stack_a[argc - 1];
	char	*stack_b[argc - 1];
	char	*cmd;
	int		size[2];

	stack_init(stack_a, stack_b, argv, argc - 2);
	size[0] = (int)sizeof(stack_a) / 8;
	size[1] = 0;
	while (get_next_line(0, &cmd))
	{
		operations(cmd, stack_a, stack_b, size);
		free(cmd);
	}
	free(cmd);
	checka(stack_a, stack_b, size[0]);
	return (0);
}

static int	main4(int argc, char **argv)
{
	char		*stack_a[argc - 1];
	char		*stack_b[argc - 1];
	char		*cmd;
	int			size[2];

	c_stack_init(stack_a, stack_b, argv, argc - 2);
	size[0] = (int)sizeof(stack_a) / 8;
	size[1] = 0;
	ft_putendl("\n\033[0;32mInitializing stacks...\033[0m");
	c_disp_lists(stack_a, stack_b, size[0], size[1]);
	while (get_next_line(0, &cmd))
	{
		c_operations(cmd, stack_a, stack_b, size);
		ft_putstr("\n\033[01;33mExecuting operation:\033[0;32m ");
		ft_putendl(cmd);
		ft_putstr("\033[0m");
		c_disp_lists(stack_a, stack_b, size[0], size[1]);
		free(cmd);
	}
	free(cmd);
	c_checka(stack_a, stack_b, size[0]);
	return (0);
}

int			main(int argc, char **argv)
{
	char	*list[100000];
	int		num;

	num = 0;
	if (argc > 1 && ft_strcmp(argv[1], "-v") != 0
		&& ft_strcmp(argv[1], "-c") != 0)
	{
		arg_format(argc - 1, &argv[1], &num, list);
		main3(num + 1, list);
	}
	else if (argc > 2)
	{
		arg_format(argc - 2, &argv[2], &num, list);
		if (ft_strcmp(argv[1], "-v") == 0)
			main2(num + 1, list);
		else if (ft_strcmp(argv[1], "-c") == 0)
			main4(num + 1, list);
	}
	return (0);
}
