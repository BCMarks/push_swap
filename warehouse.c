/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warehouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:42:54 by bmarks            #+#    #+#             */
/*   Updated: 2019/07/01 12:43:35 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libps.h"

void	push_stack(char **give, char **get, int *sz_give, int *sz_get)
{
	int		len_give;
	int		len_get;
	int		tmp_give;

	len_give = *sz_give - 1;
	len_get = *sz_get + 1;
	tmp_give = len_give;
	while (--len_get > 0)
		get[len_get] = get[len_get - 1];
	get[0] = give[0];
	while (--tmp_give >= 0)
		give[len_give - tmp_give - 1] = give[len_give - tmp_give];
	give[len_give] = "";
	*sz_give -= 1;
	*sz_get += 1;
}

void	rot_stack(char **stack, int *size)
{
	int		len;
	int		tmp;
	char	*top;

	if (*size > 1)
	{
		len = *size - 1;
		tmp = len;
		top = stack[0];
		while (--tmp >= 0)
			stack[len - tmp - 1] = stack[len - tmp];
		stack[len] = top;
	}
}

void	revrot_stack(char **stack, int *size)
{
	int		len;
	int		tmp;
	char	*bot;

	if (*size > 1)
	{
		len = *size - 1;
		tmp = -1;
		bot = stack[len];
		while (++tmp < len)
			stack[len - tmp] = stack[len - tmp - 1];
		stack[0] = bot;
	}
}
