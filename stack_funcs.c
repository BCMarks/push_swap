/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:55:55 by bmarks            #+#    #+#             */
/*   Updated: 2019/07/22 15:30:40 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libps.h"

static void	justified(size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		ft_putchar(' ');
}

void		disp_lists(char **stack1, char **stack2, int size_a, int size_b)
{
	int	i;
	int	peak;

	i = -1;
	if (size_a > size_b)
		peak = size_a;
	else
		peak = size_b;
	ft_putendl("------------------------------------------------------");
	ft_putendl("|\t  STACK_A\t  ||\t     STACK_B\t     |");
	ft_putendl("------------------------------------------------------");
	while (++i < peak)
	{
		ft_putstr("|\t");
		justified(10 - ft_strlen(stack1[i]));
		ft_putstr(stack1[i]);
		ft_putstr("\t  ||\t   ");
		justified(10 - ft_strlen(stack2[i]));
		ft_putstr(stack2[i]);
		ft_putendl("\t     |");
	}
	ft_putendl("------------------------------------------------------");
}

void		stack_init(char **stack_a, char **stack_b, char **list, int size)
{
	int		i;
	int		j;
	char	*k;

	i = -1;
	while (++i <= size)
	{
		k = ft_itoa(ft_atoi(list[i]));
		if (ft_strcmp(list[i], k) != 0)
			error_snake();
		stack_a[i] = list[i];
		stack_b[i] = "";
		ft_strdel(&k);
	}
	i = -1;
	while (++i <= size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (ft_strcmp(stack_a[i], stack_a[j]) == 0)
				error_snake();
			j++;
		}
	}
}

int			checka(char **stack_a, char **stack_b, int size)
{
	int	i;
	int j;

	i = -1;
	if (ft_strcmp("", stack_b[0]) == 0)
	{
		while (++i < size)
		{
			j = i + 1;
			while (j < size)
			{
				if (ft_atoi(stack_a[i]) > ft_atoi(stack_a[j]))
				{
					ft_putendl("KO");
					return (0);
				}
				j++;
			}
		}
		ft_putendl("OK");
	}
	else
		ft_putendl("KO");
	return (0);
}

void		arg_format(int n, char **arg, int *num, char **list)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = 0;
	j = 0;
	k = 0;
	while (i < n)
	{
		tmp = ft_strsplit(arg[i], ' ');
		while (tmp[j] != NULL)
		{
			list[k++] = tmp[j++];
			*num += 1;
		}
		free(tmp);
		j = 0;
		i++;
	}
}
