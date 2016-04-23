/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 22:41:17 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/23 01:15:00 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** a few basic string functions
*/

#include "hotrace.h"

size_t	ft_strlen(const char *s)
{
	const char	*tmp;

	tmp = s;
	while (*tmp)
		tmp++;
	return (size_t)(tmp - s);
}

void	ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_puterr(const char *s)
{
	write(2, s, ft_strlen(s));
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2 && s1++ && s2++)
		;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_bzero(void *s, size_t n)
{
	char *swap;

	if (n)
	{
		swap = s;
		while (n--)
			*swap++ = 0;
	}
}
