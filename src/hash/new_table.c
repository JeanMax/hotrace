/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 00:27:00 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/23 02:38:35 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** create a new hash table
*/

#include "hash.h"

t_htable				*new_table(size_t bucket_size)
{
	t_htable	*new;

	new = (t_htable *)malloc(sizeof(t_htable));
	ft_bzero((void *)new, sizeof(t_htable));
	new->bucket = (t_list **)malloc(sizeof(t_list *) * bucket_size);
	ft_bzero((void *)new->bucket, sizeof(t_list *) * bucket_size);
	new->bucket_size = bucket_size;
	return (new);
}
