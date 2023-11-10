/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:05:57 by okraus            #+#    #+#             */
/*   Updated: 2023/11/10 12:41:03 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

static void	ft_putscore(t_max *max)
{
	max->map->steps++;
	max->score += 500;
}

static void	ft_domovep(t_max *max, int d)
{
	if (d == 8 && max->map->p > 0)
	{
		max->img->pi[0].y -= BLOCK_HEIGHT;
		max->map->py--;
	}
	if (d == 4 && max->map->p > 0)
	{
		max->img->pi[0].y += BLOCK_HEIGHT;
		max->map->py++;
	}
	if (d == 2 && max->map->p > 0)
	{
		max->img->pi[0].x -= BLOCK_WIDTH;
		max->map->px--;
	}
	if (d == 1 && max->map->p > 0)
	{
		max->img->pi[0].x += BLOCK_WIDTH;
		max->map->px++;
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
	if (d == 1)
		x++;
	if (d == 2)
		x--;
	if (d == 4)
		y++;
	if (d == 8)
		y--;
	ft_moveplayer2(max, x, y, d);
}

// else if (t == 1)
// 	ft_killplayer();
// else if (t == 2)
// 	ft_wingame();
// else if (t == 3)
// 	ft_stepondoor(); maybe if p = 2?
