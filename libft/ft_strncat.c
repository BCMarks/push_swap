/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarks <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:57:19 by bmarks            #+#    #+#             */
/*   Updated: 2019/06/10 15:59:10 by bmarks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(s1 + i))
		i++;
	while (*(s2 + j) && n > 0)
	{
		*(s1 + i) = *(s2 + j);
		i++;
		j++;
		n--;
	}
	*(s1 + i) = '\0';
	return (s1);
}
