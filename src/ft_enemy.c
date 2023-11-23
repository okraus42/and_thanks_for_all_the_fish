/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:47:19 by okraus            #+#    #+#             */
/*   Updated: 2023/11/23 10:02:24 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

void	ft_check_player(t_max *max, int i)
{
	if (max->map->px == max->map->ex[i] && max->map->py == max->map->ey[i])
	{
		max->map->p = 0;
		max->death = 1;
		max->lives--;
		max->score -= 25000;
		if (max->lives)
			ft_soundeffect(max->ev, DEATH2, 256);
		else
			ft_soundeffect(max->ev, GAMEOVER, 256);
		ft_printf("%14.*^*CEnemy got you and you are now dead:(%C\n", 0xFFFFFF, 0x880000);
		ft_printf("%25.*^*CCurrent score: %i%C\n", 0xFFFFFF, 0x888800, max->score);
		//mlx_close_window(max->mlx);
	}
}

void	ft_moveenemy(t_max *max, int i, int x, int y)
{
	int	d;

	x = max->map->ex[i];
	y = max->map->ey[i];
	d = ft_checkmovee(max->map, i, x, y);
	if (d)
	{
		ft_domovee(max, i, d);
		ft_check_player(max, i);
	}
}

void	ft_moveenemies(t_max *max)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	while (i < max->map->et)
	{
		if (max->map->e[i])
		{
			ft_moveenemy(max, i, x, y);
			i++;
		}
	}
}
