/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_stack_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:48:15 by bmarks            #+#    #+#             */
/*   Updated: 2019/07/22 15:29:37 by bmarks           ###   ########.fr       */
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

static void	c_change(char **stack1, char **stack2, int i, int n)
{
	char	*colour;

	colour = (n == 0 || n == 2) ? "\033[0;36m" : "\033[0;33m";
	ft_putstr("|\t");
	justified(10 - ft_strlen(stack1[i]));
	ft_putstr(colour);
	ft_putstr(stack1[i]);
	ft_putstr("\033[0m\t  ||\t   ");
	justified(10 - ft_strlen(stack2[i]));
	colour = (n == 0 || n == 1) ? "\033[0;36m" : "\033[0;33m";
	ft_putstr(colour);
	ft_putstr(stack2[i]);
	ft_putendl("\033[0m\t     |");
}

void		c_disp_lists(char **stack1, char **stack2, int size_a, int size_b)
{
	int			i;
	int			peak;
	static char	*a[1000000];
	static char	*b[1000000];

	i = -1;
	peak = size_a > size_b ? size_a : size_b;
	ft_putendl("------------------------------------------------------");
	ft_putstr("|\033[1;36m\t  STACK_A\t \033[0m ||");
	ft_putendl("\t\033[1;36m     STACK_B\t     \033[0m|");
	ft_putendl("------------------------------------------------------");
	while (++i < peak)
	{
		if (a[i] == NULL && b[i] == NULL)
			c_change(stack1, stack2, i, 0);
		else if (ft_strstr(b[i], stack2[i]) == b[i])
			ft_strstr(a[i], stack1[i]) == a[i] ?
				c_change(stack1, stack2, i, 0) : c_change(stack1, stack2, i, 1);
		else if (ft_strstr(b[i], stack2[i]) != b[i])
			ft_strstr(a[i], stack1[i]) == a[i] ?
				c_change(stack1, stack2, i, 2) : c_change(stack1, stack2, i, 3);
		a[i] = stack1[i];
		b[i] = stack2[i];
	}
	ft_putendl("------------------------------------------------------");
}

void		c_stack_init(char **stack_a, char **stack_b, char **list, int size)
{
	int		i;
	int		j;
	char	*k;

	i = -1;
	while (++i <= size)
	{
		k = ft_itoa(ft_atoi(list[i]));
		if (ft_strcmp(list[i], k) != 0)
			c_error_snake();
		stack_a[i] = list[i];
		stack_b[i] = "";
		free(k);
	}
	i = -1;
	while (++i <= size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (ft_strcmp(stack_a[i], stack_a[j]) == 0)
				c_error_snake();
			j++;
		}
	}
}

int			c_checka(char **stack_a, char **stack_b, int size)
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
					ft_putendl("\033[1;31mKO\033[0m");
					return (0);
				}
				j++;
			}
		}
		ft_putendl("\033[1;32mOK\033[0m");
	}
	else
		ft_putendl("\033[1;31mKO\033[0m");
	return (0);
}
