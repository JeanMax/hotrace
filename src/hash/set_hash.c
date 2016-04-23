/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 00:47:12 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/23 02:38:21 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** add a new key/value pair in the table
*/

#include "hash.h"

static void	move_link(t_list **new_bucket, t_list *link, size_t bucket_size)
{
	t_list	**dst;
	t_list	*next;

	while (link)
	{
		next = link->next;
		dst = new_bucket + link->hash % bucket_size;
		link->next = *dst;
		*dst = link;
		link = next;
	}
}

static void	resize_table(t_htable *table)
{
	t_list	**new_bucket;
	t_list	**swap;
	size_t	size;

	table->bucket_size *= RESIZE_FACTOR;
	new_bucket = (t_list **)malloc(sizeof(t_list *) * table->bucket_size);
	size = table->bucket_size;
	swap = table->bucket;
	while (size--)
		if (*swap)
			move_link(new_bucket, *swap++, table->bucket_size);
	free(table->bucket);
	table->bucket = new_bucket;
}

t_bool		set_hash(t_htable *table, char *key, char *value)
{
	t_list	*new;
	t_list	**link;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (FALSE);
	new->key = key; //TODO: check if key already exists?
	new->value = value; //TODO: malloc key/value?
	new->hash = jenkins_hash(key);
	link = table->bucket + new->hash % table->bucket_size;
	new->next = *link;
	*link = new;
	table->length++;
	if (table->length / table->bucket_size > RESIZE_TRIGGER)
		resize_table(table);
	return (TRUE);
}
