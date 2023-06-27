/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:06:00 by okraus            #+#    #+#             */
/*   Updated: 2023/06/26 16:29:12 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_flood_map(t_map *map, int x, int y)
{
	if (map->m[y][x] == '1' || map->m[y][x] > 'a')
		return ;
	if (map->m[y][x] == '0')
		map->m[y][x] = 'O';
	map->m[y][x] += 32;
	ft_flood_map(map, x + 1, y);
	ft_flood_map(map, x - 1, y);
	ft_flood_map(map, x, y + 1);
	ft_flood_map(map, x, y - 1);
}

void	ft_init_key(t_controls *key, int a)
{
	key->w = 0;
	key->s = 0;
	key->a = 0;
	key->d = 0;
	if (a == 1)
		key->w++;
	else if (a == 2)
		key->s++;
	else if (a == 3)
		key->a++;
	else if (a == 4)
		key->d++;
}

void	ft_init_map(t_map *map)
{
	map->m = NULL;
	map->s = NULL;
	map->w = 0;
	map->h = 0;
	map->p = 0;
	map->px = 0;
	map->py = 0;
	map->ct = 0;
	map->cr = 0;
	map->c = NULL;
	map->cx = NULL;
	map->cy = NULL;
	map->et = 0;
	map->e = NULL;
	map->ex = NULL;
	map->ey = NULL;
	map->x = 0;
	map->xx = 0;
	map->xy = 0;
	map->steps = 0;
}

void	ft_init_keys(t_controls *key)
{
	key->w = 0;
	key->s = 0;
	key->a = 0;
	key->d = 0;
	key->space = 0;
	key->ctrl = 0;
	key->time = 0;
	key->t = 0;
}
