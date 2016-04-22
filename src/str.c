/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 22:41:17 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/22 23:19:05 by mcanal           ###   ########.fr       */
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
