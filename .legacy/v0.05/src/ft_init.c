/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:06:00 by okraus            #+#    #+#             */
/*   Updated: 2024/03/05 12:58:14 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

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
	if (a == UP)
		key->w++;
	else if (a == DOWN)
		key->s++;
	else if (a == LEFT)
		key->a++;
	else if (a == RIGHT)
		key->d++;
}

void	ft_init_map(t_map *map)
{
	map->m = NULL;
	//map->s = NULL;
	map->w = 0;
	map->h = 0;
	map->p = 0;
	map->po = RIGHT;
	map->px = 0;
	map->py = 0;
	map->ct = 0;
	map->cr = 0;
	map->c = NULL;
	map->cx = NULL;
	map->cy = NULL;
	map->et = 0;
	map->e = NULL;
	map->eo = NULL;
	map->ex = NULL;
	map->ey = NULL;
	map->esx = NULL;
	map->esy = NULL;
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
