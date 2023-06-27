/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:17:59 by okraus            #+#    #+#             */
/*   Updated: 2023/06/26 16:19:38 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_put_enemies2(t_max *max, mlx_image_t *en_img)
{
	int			x;
	int			y;
	int			i;

	y = 0;
	i = 0;
	while (max->map->m[y])
	{
		x = 0;
		while (max->map->m[y][x])
		{
			if (max->map->m[y][x] == 's')
			{
				if (mlx_image_to_window(max->mlx, en_img, x * 32, y * 32) < 0)
					exit(-5);
				max->img->ei = en_img->instances;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_enemies(t_max *max)
{
	xpm_t		*en_xpm;
	mlx_image_t	*en_img;

	en_xpm = mlx_load_xpm42("./imgs/enemy1.xpm42");
	if (!en_xpm)
		exit(-4);
	en_img = mlx_texture_to_image(max->mlx, &en_xpm->texture);
	if (!en_img)
		exit(-8);
	ft_put_enemies2(max, en_img);
	mlx_delete_xpm42(en_xpm);
}

void	ft_put_player2(t_max *max, mlx_image_t *play_img)
{
	int			x;
	int			y;

	y = 0;
	while (max->map->m[y])
	{
		x = 0;
		while (max->map->m[y][x])
		{
			if (max->map->m[y][x] == 'p')
			{
				if (mlx_image_to_window(max->mlx, play_img, x * 32, y * 32) < 0)
					exit(-5);
				max->img->pi = play_img->instances;
				max->map->px = x;
				max->map->py = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_player(t_max *max)
{
	xpm_t		*play_xpm;
	mlx_image_t	*play_img;

	play_xpm = mlx_load_xpm42("./imgs/player.xpm42");
	if (!play_xpm)
		exit(-4);
	play_img = mlx_texture_to_image(max->mlx, &play_xpm->texture);
	if (!play_img)
		exit(-8);
	ft_put_player2(max, play_img);
	mlx_delete_xpm42(play_xpm);
}
