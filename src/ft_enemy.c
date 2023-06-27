/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:47:19 by okraus            #+#    #+#             */
/*   Updated: 2023/06/26 16:21:51 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_check_player(t_max *max, int i)
{
	if (max->map->px == max->map->ex[i] && max->map->py == max->map->ey[i])
	{
		max->map->p = 0;
		ft_printf("\n\nEnemy got you and you are now dead:(\n\n\n");
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
