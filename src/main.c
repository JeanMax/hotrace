/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 00:12:49 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/23 02:06:43 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main...
*/

#include "hotrace.h"

int				main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_puterr(*av);
		ft_puterr(": too many arguments\n");
		return (EXIT_FAILURE);
	}
	/*
	if (!parsing()) //TODO
	{
		ft_puterr(*av);
		ft_puterr(": parsing failed\n");
		return (EXIT_FAILURE);
	}
	*/
	return (EXIT_SUCCESS);
}
