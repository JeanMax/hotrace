/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:43:26 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/23 17:23:50 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char		*ft_strchr(const char *s, int i) //TODO: move
{
	while (*s != (char)i)
		if (!*s++)
			return (NULL);
	return ((char *)s);
}

static void		concat(char **line, char *src)
{
	char	*new;
	char	*swap;

	new = malloc(sizeof(char) * (ft_strlen(*line) + ft_strlen(src)));
	swap = new;
	while (**line)
		*swap++ = *(*line++);
	while ((*swap++ = *src++))
		;
	free(*line);
	*line = new;
}


static void		handle_query(t_htable *table, char *key, char *print_buf)
{
	char		*value;

	if (!(value = get_hash(table, key)))
	{
		add_to_buffer(print_buf, key);
		add_to_buffer(print_buf, ": Not found.\n");
	}
	else
	{
		add_to_buffer(print_buf, value);
		add_to_buffer(print_buf, "\n");
	}	
}

static void		parse_buf(t_htable *table, char *line, size_t mode)
{
	char		*eol;
	
	eol = strchr(line, '\n');
	if (*(eol + 1) == '\n')
		handle_query();
	if (!(mode % 2))
		
}

static void		print_values(t_htable *table) //TODO
{
	char		print_buf[BUFF_SIZE];

	ft_bzero(print_buf, BUFF_SIZE);
}

t_bool			parsing(void)
{
	t_htable	*table;
	char		read_buf[BUFF_SIZE];
	char		*line;
	ssize_t		ret;
	size_t		mode;

	table = new_table();
	line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	ft_bzero(line, BUFF_SIZE);
	ft_bzero(read_buf, BUFF_SIZE);

	mode = READ_KEY;
	while ((ret = read(0, read_buf, BUFF_SIZE - 1)) > 0)
	{
		read_buf[ret] = 0;
		concat(&line, read_buf);
		if (strchr(read_buf, '\n') || ret < BUFF_SIZE)
			parse_buf(table, line, mode++);
		//TODO
	}

	ft_putstr(print_buf);
	del_table(table);
	return (ret >= 0);
}
