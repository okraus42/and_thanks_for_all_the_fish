/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:47:19 by okraus            #+#    #+#             */
/*   Updated: 2023/11/10 10:31:59 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

void	ft_remove_collectible(t_max *max, int x, int y)
{
	int	i;

	i = 0;
	max->score += 125;
	while (i < max->map->ct)
	{
		if (max->map->cx[i] == x && max->map->cy[i] == y)
		{
			max->img->ci[i].x += BLOCK_WIDTH * max->map->w;
			max->img->c2i[i].x += BLOCK_WIDTH * max->map->w;
		}
		i++;
	}
}

void	ft_check_time(t_max *max)
{
	int	i;

	i = 0;
	while (i < max->map->ct)
	{
		if (!max->key->switch_collect && max->key->mtime & 0x80
			&& max->map->c[i])
		{
			max->img->ci[i].x += BLOCK_WIDTH * max->map->w;
			max->img->c2i[i].x -= BLOCK_WIDTH * max->map->w;
		}
		if (max->key->switch_collect && !(max->key->mtime & 0x80)
			&& max->map->c[i])
		{
			max->img->ci[i].x -= BLOCK_WIDTH * max->map->w;
			max->img->c2i[i].x += BLOCK_WIDTH * max->map->w;
		}
		i++;
	}
	if (!max->key->switch_collect && max->key->mtime & 0x80
			&& max->map->c[i])
			max->key->switch_collect = 1;
		if (max->key->switch_collect && !(max->key->mtime & 0x80)
			&& max->map->c[i])
			max->key->switch_collect = 0;
}

void	ft_open_door(t_max *max)
{
	max->img->dci[0].x += BLOCK_WIDTH * max->map->w;
	max->score += 1000;
}

void	ft_check_door(t_max *max)
{
	if (!max->map->cr && max->map->p && max->map->px == max->map->xx
		&& max->map->py == max->map->xy)
	{
		max->map->p = -1;
		max->score *= 2;
		max->time += 2500;
		max->lives += 1;
		ft_printf("%22CYou win!%0C\n");
		ft_printf("%52CCurrent score: %i%0C\n", max->score);
		mlx_close_window(max->mlx);
	}
}
