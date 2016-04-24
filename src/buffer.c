/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 01:46:34 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/24 18:16:40 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** concat string into buffer, print the string if buffer full
*/

#include "hotrace.h"

void		add_to_buffer(char *buf, const char *s)
{
	static size_t	len = 0;

	buf += len;
	while (*s)
	{
		*(buf++) = *(s++);
		len++;
		if (len == BUFF_SIZE)
		{
			buf -= len;
			write(1, buf, len);
			ft_bzero(buf, len);
			len = 0;
		}
	}
}
