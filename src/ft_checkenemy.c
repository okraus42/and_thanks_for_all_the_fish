/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkenemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:21:31 by okraus            #+#    #+#             */
/*   Updated: 2023/06/26 19:27:35 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_domovee(t_max *max, int i, int d)
{
	if (d == 4)
	{
		max->img->ei[i].y -= 32;
		max->map->ey[i]--;
	}
	if (d == 2)
	{
		max->img->ei[i].y += 32;
		max->map->ey[i]++;
	}
	if (d == 3)
	{
		max->img->ei[i].x -= 32;
		max->map->ex[i]--;
	}
	if (d == 1)
	{
		max->img->ei[i].x += 32;
		max->map->ex[i]++;
	}
}

static int	ft_checkmovee2(t_map *map, int i, int x, int y)
{
	if (map->ex[i] > map->px && map->m[y][x - 1] != '1' && (i + map->steps % 3))
		return (3);
	if (map->ey[i] > map->py && map->m[y - 1][x] != '1' && map->steps % 3)
		return (4);
	if (map->m[y][x - 1] != '1' && ((i + map->steps) % 3))
		return (3);
	if (map->m[y - 1][x] != '1')
		return (4);
	if (map->m[y][x + 1] != '1' && ((i + map->steps) % 2))
		return (1);
	if (map->m[y + 1][x] != '1')
		return (2);
	if (map->m[y][x - 1] != '1')
		return (3);
	if (map->m[y][x + 1] != '1')
		return (1);
	return (0);
}

int	ft_checkmovee(t_map *map, int i, int x, int y)
{
	if (map->ey[i] > map->py + 3 && map->m[y - 1][x] != '1'
			&& (i + map->steps) % 4)
		return (4);
	if (map->ex[i] > map->px + 3 && map->m[y][x - 1] != '1'
			&& (i + map->steps) % 4)
		return (3);
	if (map->ey[i] < map->py - 2 && map->m[y + 1][x] != '1'
			&& (i + map->steps) % 3)
		return (2);
	if (map->ex[i] < map->px - 2 && map->m[y][x + 1] != '1'
			&& (i + map->steps) % 3)
		return (1);
	if (map->ex[i] < map->px && map->m[y][x + 1] != '1'
			&& !((i + map->steps) % 2))
		return (1);
	if (map->ey[i] < map->py && map->m[y + 1][x] != '1'
			&& !((1 + i + map->steps) % 2))
		return (2);
	return (ft_checkmovee2(map, i, x, y));
}

void	ft_check_enemy(t_max *max)
{
	int	i;

	i = 0;
	while (i < max->map->et && max->map->e[i])
	{
		if (max->map->e[i] && max->map->px == max->map->ex[i]
			&& max->map->py == max->map->ey[i])
		{
			max->map->p = 0;
			ft_printf("\n\nYou stepped on enemy and died:(\n\n\n");
		}
		i++;
	}
}
