/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:01:57 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/22 23:54:46 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H

# define HOTRACE_H

# define BUFF_SIZE		1024

# define TRUE			1
# define FALSE			0

typedef unsigned int	t_uint;
typedef int				t_bool;

# include "stdlib.h"
# include "unistd.h"

/*
** list struct - simple linked list
*/
typedef struct s_list	t_list;
struct	s_list
{
	char	*key;
	char	*value;
	t_list	*next;
};

/*
** htable struct - hash table
*/
typedef struct s_htable	t_htable;
struct	s_htable
{
	size_t	length;
	t_list	**bucket;
	size_t	bucket_size;
};

/*
** str.c
*/
void					ft_putstr(const char *s);
void					ft_puterr(const char *s);
size_t					ft_strlen(const char *s);

/*
** PARSING
** todo.c
*/
t_bool					parsing(void);

/*
** HASH
** todo.c
*/
t_htable				*new_table(size_t bucket_size);
char					*get_hash(t_htable *table, const char *key);
char					*set_hash(t_htable *table, \
									const char *key, const char *value);

#endif
