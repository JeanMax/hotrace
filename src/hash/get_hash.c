/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 01:10:23 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/23 02:40:21 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** if the key is found in the table the corresponding value is returned,
** otherwise NULL
*/

#include "hash.h"

char		*get_hash(t_htable *table, char *key)
{
	t_list	*link;

	link = *(table->bucket + jenkins_hash(key) % table->bucket_size);
	while (link)
	{
		if (!ft_strcmp(link->key, key))
			return (link->value);
		link = link->next;
	}
	return (NULL);
}
