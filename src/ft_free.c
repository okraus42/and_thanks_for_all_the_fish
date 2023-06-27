/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:54:12 by okraus            #+#    #+#             */
/*   Updated: 2023/06/25 17:23:46 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_free(t_max *max)
{
	ft_free_split(max->map->m);
	free(max->map->c);
	max->map->c = NULL;
	free(max->map->cx);
	max->map->cx = NULL;
	free(max->map->cy);
	max->map->cy = NULL;
	if (max->map->et)
	{
		free(max->map->e);
		max->map->e = NULL;
		free(max->map->ex);
		max->map->ex = NULL;
		free(max->map->ey);
		max->map->ey = NULL;
	}
	free(max->map->s);
}

void	ft_exit(t_map *map, int n)
{
	ft_free_split(map->m);
	exit(n);
}
