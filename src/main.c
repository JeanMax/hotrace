/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 00:12:49 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/23 15:22:36 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main...
*/

#include "hotrace.h"

/* debug */
static void test_hash(void)
{
	t_htable *table = new_table();
	char print_buf[BUFF_SIZE];

	ft_bzero(print_buf, BUFF_SIZE);
	set_hash(table, "key1", "value1");
	set_hash(table, "key2", "value2");
	set_hash(table, "key3", "value3");

	add_to_buffer(print_buf, get_hash(table, "key3"));
	add_to_buffer(print_buf, get_hash(table, "key2"));
	add_to_buffer(print_buf, get_hash(table, "key1"));

	ft_putstr(print_buf);
	del_table(table);
}
/* /debug */

int				main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_puterr(*av);
		ft_puterr(": too many arguments\n");
		return (EXIT_FAILURE);
	}
	test_hash();				/* debug */
	if (!parsing())
	{
		ft_puterr(*av);
		ft_puterr(": parsing failed\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
