/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:06:11 by okraus            #+#    #+#             */
/*   Updated: 2023/06/26 15:36:45 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_update_map3(t_map *map, int y, int c, int s)
{
	int	x;

	while (map->m[y])
	{
		x = 0;
		while (map->m[y][x])
		{
			if (map->m[y][x] == 's')
			{
				map->e[s] = 1;
				map->ex[s] = x;
				map->ey[s] = y;
				s++;
			}
			else if (map->m[y][x] == 'c')
			{
				map->c[c] = 1;
				map->cx[c] = x;
				map->cy[c] = y;
				c++;
			}
			x++;
		}
		y++;
	}
}

void	ft_update_map2(t_map *map)
{
	int	y;
	int	c;
	int	s;

	y = 0;
	c = 0;
	s = 0;
	ft_update_map3(map, y, c, s);
}

void	ft_update_map(t_map *map)
{
	map->cr = map->ct;
	map->c = malloc(map->ct * sizeof(int));
	if (!map->c)
		exit(-1);
	map->cx = malloc(map->ct * sizeof(int));
	if (!map->cx)
		exit(-1);
	map->cy = malloc(map->ct * sizeof(int));
	if (!map->cy)
		exit(-1);
	if (map->et)
	{
		map->e = malloc(map->et * sizeof(int));
		if (!map->e)
			exit(-1);
		map->ex = malloc(map->et * sizeof(int));
		if (!map->ex)
			exit(-1);
		map->ey = malloc(map->et * sizeof(int));
		if (!map->ey)
			exit(-1);
	}
	ft_update_map2(map);
}
