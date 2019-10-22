/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_snake.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:06:16 by bmarks            #+#    #+#             */
/*   Updated: 2019/07/16 10:56:07 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

void	error_snake(void)
{
	ft_putendl_fd("Error", 2);
	exit(-1);
}

void	c_error_snake(void)
{
	ft_putendl_fd("\033[1;31mError\033[0m", 2);
	exit(-1);
}
