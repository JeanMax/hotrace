/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:03:10 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/24 13:47:58 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H

# define HASH_H

# define INITIAL_BUCKET_SIZE	1024
# define RESIZE_TRIGGER			0.75
# define RESIZE_FACTOR			8

# include "hotrace.h"

/*
** jenkins_hash.c
*/
size_t					jenkins_hash(const char *value);

#endif
