/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkenemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:21:31 by okraus            #+#    #+#             */
/*   Updated: 2023/11/11 17:02:09 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

static void	ft_domoveeup(t_max *max, int i)
{
	max->img->ei[i].y -= BLOCK_HEIGHT;
	max->img->eli[i].y -= BLOCK_HEIGHT;
	max->img->eri[i].y -= BLOCK_HEIGHT;
	max->img->eui[i].y -= BLOCK_HEIGHT;
	max->img->edi[i].y -= BLOCK_HEIGHT;
	max->map->ey[i]--;
	if (max->map->eo[i] & DOWN)
	{
		max->img->edi[i].x += BLOCK_HEIGHT * max->map->w;
		max->img->eui[i].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->eo[i] & LEFT)
	{
		max->img->eli[i].x += BLOCK_HEIGHT * max->map->w;
		max->img->eui[i].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->eo[i] & RIGHT)
	{
		max->img->eri[i].x += BLOCK_HEIGHT * max->map->w;
		max->img->eui[i].x -= BLOCK_HEIGHT * max->map->w;
	}
	max->map->eo[i] = UP;
}

static void	ft_domoveedown(t_max *max, int i)
{
	max->img->ei[i].y += BLOCK_HEIGHT;
	max->img->eli[i].y += BLOCK_HEIGHT;
	max->img->eri[i].y += BLOCK_HEIGHT;
	max->img->eui[i].y += BLOCK_HEIGHT;
	max->img->edi[i].y += BLOCK_HEIGHT;
	max->map->ey[i]++;
	if (max->map->eo[i] & UP)
	{
		max->img->eui[i].x += BLOCK_HEIGHT * max->map->w;
		max->img->edi[i].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->eo[i] & LEFT)
	{
		max->img->eli[i].x += BLOCK_HEIGHT * max->map->w;
		max->img->edi[i].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->eo[i] & RIGHT)
	{
		max->img->eri[i].x += BLOCK_HEIGHT * max->map->w;
		max->img->edi[i].x -= BLOCK_HEIGHT * max->map->w;
	}
	max->map->eo[i] = DOWN;
}

static void	ft_domoveeright(t_max *max, int i)
{
	max->img->ei[i].x += BLOCK_HEIGHT;
	max->img->eli[i].x += BLOCK_HEIGHT;
	max->img->eri[i].x += BLOCK_HEIGHT;
	max->img->eui[i].x += BLOCK_HEIGHT;
	max->img->edi[i].x += BLOCK_HEIGHT;
	max->map->ex[i]++;
	if (max->map->eo[i] & DOWN)
	{
		max->img->edi[i].x += BLOCK_HEIGHT * max->map->w;
		max->img->eri[i].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->eo[i] & LEFT)
	{
		max->img->eli[i].x += BLOCK_HEIGHT * max->map->w;
		max->img->eri[i].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->eo[i] & UP)
	{
		max->img->eui[i].x += BLOCK_HEIGHT * max->map->w;
		max->img->eri[i].x -= BLOCK_HEIGHT * max->map->w;
	}
	max->map->eo[i] = RIGHT;
}

static void	ft_domoveeleft(t_max *max, int i)
{
	max->img->ei[i].x -= BLOCK_HEIGHT;
	max->img->eli[i].x -= BLOCK_HEIGHT;
	max->img->eri[i].x -= BLOCK_HEIGHT;
	max->img->eui[i].x -= BLOCK_HEIGHT;
	max->img->edi[i].x -= BLOCK_HEIGHT;
	max->map->ex[i]--;
	if (max->map->eo[i] & DOWN)
	{
		max->img->edi[i].x += BLOCK_HEIGHT * max->map->w;
		max->img->eli[i].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->eo[i] & UP)
	{
		max->img->eui[i].x += BLOCK_HEIGHT * max->map->w;
		max->img->eli[i].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->eo[i] & RIGHT)
	{
		max->img->eri[i].x += BLOCK_HEIGHT * max->map->w;
		max->img->eli[i].x -= BLOCK_HEIGHT * max->map->w;
	}
	max->map->eo[i] = LEFT;
}

void	ft_domovee(t_max *max, int i, int d)
{
	if (d == UP)
	{
		ft_domoveeup(max, i);
	}
	if (d == DOWN)
	{
		ft_domoveedown(max, i);
	}
	if (d == LEFT)
	{
		ft_domoveeleft(max, i);
	}
	if (d == RIGHT)
	{
		ft_domoveeright(max, i);
	}
}

static int	ft_checkmovee2(t_map *map, int i, int x, int y)
{
	if (map->ex[i] > map->px && map->m[y][x - 1] != '1' && (i + map->steps % 3))
		return (LEFT);
	if (map->ey[i] > map->py && map->m[y - 1][x] != '1' && map->steps % 3)
		return (UP);
	if (map->m[y][x - 1] != '1' && ((i + map->steps) % 3))
		return (LEFT);
	if (map->m[y - 1][x] != '1')
		return (UP);
	if (map->m[y][x + 1] != '1' && ((i + map->steps) % 2))
		return (RIGHT);
	if (map->m[y + 1][x] != '1')
		return (DOWN);
	if (map->m[y][x - 1] != '1')
		return (LEFT);
	if (map->m[y][x + 1] != '1')
		return (RIGHT);
	return (0);
}

int	ft_checkmovee(t_map *map, int i, int x, int y)
{
	if (map->ey[i] > map->py + 3 && map->m[y - 1][x] != '1'
			&& (i + map->steps) % 4)
		return (UP);
	if (map->ex[i] > map->px + 3 && map->m[y][x - 1] != '1'
			&& (i + map->steps) % 4)
		return (LEFT);
	if (map->ey[i] < map->py - 2 && map->m[y + 1][x] != '1'
			&& (i + map->steps) % 3)
		return (DOWN);
	if (map->ex[i] < map->px - 2 && map->m[y][x + 1] != '1'
			&& (i + map->steps) % 3)
		return (RIGHT);
	if (map->ex[i] < map->px && map->m[y][x + 1] != '1'
			&& !((i + map->steps) % 2))
		return (RIGHT);
	if (map->ey[i] < map->py && map->m[y + 1][x] != '1'
			&& !((1 + i + map->steps) % 2))
		return (DOWN);
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
			max->death = 1;
			max->lives--;
			max->score -= 50000;
			if (max->lives)
				ft_soundeffect(max->ev, DEATH1);
			else
				ft_soundeffect(max->ev, GAMEOVER);
			ft_printf("%21CYou stepped on enemy and died:(%0C\n");
			ft_printf("%55CCurrent score: %i%0C\n", max->score);
			//mlx_close_window(max->mlx);
		}
		i++;
	}
}
