/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:43:26 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/23 14:56:47 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool			parsing(void)
{
	t_htable	*table;
	char		print_buf[BUFF_SIZE];
	char		read_buf[BUFF_SIZE];
	ssize_t		ret;

	table = new_table();
	ft_bzero(print_buf, BUFF_SIZE);
	ft_bzero(read_buf, BUFF_SIZE);

	while ((ret = read(0, read_buf, BUFF_SIZE - 1)) > 0)
	{
		read_buf[ret] = 0;
		//TODO
	}

	ft_putstr(print_buf);
	del_table(table);
	return (ret >= 0);
}
