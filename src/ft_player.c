/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:05:57 by okraus            #+#    #+#             */
/*   Updated: 2023/11/19 13:31:59 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

static void	ft_putscore(t_max *max)
{
	max->map->steps++;
	max->score += 500;
	ft_soundeffect(max->ev, MOVE);
}

static void	ft_domovepup(t_max *max)
{
	//max->img->pi[0].y -= BLOCK_HEIGHT;
	max->img->pli[0].y -= BLOCK_HEIGHT;
	max->img->pri[0].y -= BLOCK_HEIGHT;
	max->img->pui[0].y -= BLOCK_HEIGHT;
	max->img->pdi[0].y -= BLOCK_HEIGHT;
	max->map->py--;
	if (max->map->po & DOWN)
	{
		max->img->pdi[0].x += BLOCK_HEIGHT * max->map->w;
		max->img->pui[0].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->po & LEFT)
	{
		max->img->pli[0].x += BLOCK_HEIGHT * max->map->w;
		max->img->pui[0].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->po & RIGHT)
	{
		max->img->pri[0].x += BLOCK_HEIGHT * max->map->w;
		max->img->pui[0].x -= BLOCK_HEIGHT * max->map->w;
	}
	max->map->po = UP;
}

static void	ft_domovepdown(t_max *max)
{
	//max->img->pi[0].y += BLOCK_HEIGHT;
	max->img->pli[0].y += BLOCK_HEIGHT;
	max->img->pri[0].y += BLOCK_HEIGHT;
	max->img->pui[0].y += BLOCK_HEIGHT;
	max->img->pdi[0].y += BLOCK_HEIGHT;
	max->map->py++;
	if (max->map->po & UP)
	{
		max->img->pui[0].x += BLOCK_HEIGHT * max->map->w;
		max->img->pdi[0].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->po & LEFT)
	{
		max->img->pli[0].x += BLOCK_HEIGHT * max->map->w;
		max->img->pdi[0].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->po & RIGHT)
	{
		max->img->pri[0].x += BLOCK_HEIGHT * max->map->w;
		max->img->pdi[0].x -= BLOCK_HEIGHT * max->map->w;
	}
	max->map->po = DOWN;
}

static void	ft_domovepright(t_max *max)
{
	//max->img->pi[0].x += BLOCK_HEIGHT;
	max->img->pli[0].x += BLOCK_HEIGHT;
	max->img->pri[0].x += BLOCK_HEIGHT;
	max->img->pui[0].x += BLOCK_HEIGHT;
	max->img->pdi[0].x += BLOCK_HEIGHT;
	max->map->px++;
	if (max->map->po & DOWN)
	{
		max->img->pdi[0].x += BLOCK_HEIGHT * max->map->w;
		max->img->pri[0].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->po & LEFT)
	{
		max->img->pli[0].x += BLOCK_HEIGHT * max->map->w;
		max->img->pri[0].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->po & UP)
	{
		max->img->pui[0].x += BLOCK_HEIGHT * max->map->w;
		max->img->pri[0].x -= BLOCK_HEIGHT * max->map->w;
	}
	max->map->po = RIGHT;
}

static void	ft_domovepleft(t_max *max)
{
	//max->img->pi[0].x -= BLOCK_HEIGHT;
	max->img->pli[0].x -= BLOCK_HEIGHT;
	max->img->pri[0].x -= BLOCK_HEIGHT;
	max->img->pui[0].x -= BLOCK_HEIGHT;
	max->img->pdi[0].x -= BLOCK_HEIGHT;
	max->map->px--;
	if (max->map->po & DOWN)
	{
		max->img->pdi[0].x += BLOCK_HEIGHT * max->map->w;
		max->img->pli[0].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->po & UP)
	{
		max->img->pui[0].x += BLOCK_HEIGHT * max->map->w;
		max->img->pli[0].x -= BLOCK_HEIGHT * max->map->w;
	}
	else if (max->map->po & RIGHT)
	{
		max->img->pri[0].x += BLOCK_HEIGHT * max->map->w;
		max->img->pli[0].x -= BLOCK_HEIGHT * max->map->w;
	}
	max->map->po = LEFT;
}

static void	ft_domovep(t_max *max, int d)
{
	if (d == UP && max->map->p > 0)
	{
		ft_domovepup(max);
	}
	if (d == DOWN && max->map->p > 0)
	{
		ft_domovepdown(max);
	}
	if (d == LEFT && max->map->p > 0)
	{
		ft_domovepleft(max);
	}
	if (d == RIGHT && max->map->p > 0)
	{
		ft_domovepright(max);
	}
	ft_putscore(max);
}

static int	ft_checkmovep(t_max *max, int x, int y)
{
	if (max->map->m[y][x] != '1' || max->map->p < 1)
	{
		if (max->map->m[y][x] == 'c')
		{
			max->map->cr--;
			ft_remove_collectible(max, x, y);
			if (!max->map->cr)
				ft_open_door(max);
			max->map->m[y][x] = 'o';
		}
		return (0);
	}
	return (1);
}

void	ft_moveplayer2(t_max *max, int x, int y, int d)
{
	int	t;

	t = ft_checkmovep(max, x, y);
	if (!t)
	{
		ft_domovep(max, d);
		if (max->map->et)
			ft_check_enemy(max);
		if (max->map->et && max->map->p > 0
			&& (max->map->steps % 2 || max->map->steps % 3))
			ft_moveenemies(max);
		ft_check_door(max);
	}
	ft_init_key(max->key, 0);
}

void	ft_moveplayer(t_max *max, int d)
{
	int	x;
	int	y;

	x = max->map->px;
	y = max->map->py;
	if (d == RIGHT)
		x++;
	if (d == LEFT)
		x--;
	if (d == DOWN)
		y++;
	if (d == UP)
		y--;
	ft_moveplayer2(max, x, y, d);
}

// else if (t == 1)
// 	ft_killplayer();
// else if (t == 2)
// 	ft_wingame();
// else if (t == 3)
// 	ft_stepondoor(); maybe if p = 2?
