/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:04:17 by okraus            #+#    #+#             */
/*   Updated: 2024/04/17 15:29:40 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

void	ft_put_walls(t_max *max, mlx_image_t *wall_img)
{
	int	x;
	int	y;

	y = 0;
	while (max->map->m[y])
	{
		x = 0;
		while (max->map->m[y][x])
		{
			if (max->map->m[y][x] == '1')
			{
				if (mlx_image_to_window(max->mlx, wall_img, x * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
					exit(-5);
			}
			x++;
		}
		y++;
	}
}

void	ft_put_ground(t_max *max, mlx_image_t *grnd_img)
{
	int	x;
	int	y;

	y = 0;
	while (max->map->m[y])
	{
		x = 0;
		while (max->map->m[y][x])
		{
			if (max->map->m[y][x] != '1')
			{
				if (mlx_image_to_window(max->mlx, grnd_img, x * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
					exit(-5);
			}
			x++;
		}
		y++;
	}
}

void	ft_put_background(t_max *max)
{
	xpm_t		*wall_xpm;
	xpm_t		*ground_xpm;
	mlx_image_t	*wall_img;
	mlx_image_t	*grnd_img;

	wall_xpm = mlx_load_xpm42("./imgs/wall.xpm42");
	if (!wall_xpm)
		exit(-4);
	wall_img = mlx_texture_to_image(max->mlx, &wall_xpm->texture);
	if (!wall_img)
		exit(-8);
	ground_xpm = mlx_load_xpm42("./imgs/ground.xpm42");
	if (!ground_xpm)
		exit(-4);
	grnd_img = mlx_texture_to_image(max->mlx, &ground_xpm->texture);
	if (!grnd_img)
		exit(-8);
	ft_put_walls(max, wall_img);
	ft_put_ground(max, grnd_img);
	mlx_delete_xpm42(wall_xpm);
	mlx_delete_xpm42(ground_xpm);
}

void	ft_put_lives(t_max *max)
{
	xpm_t		*life_xpm;
	mlx_image_t	*life_img;
	int	x;
	int	y;

	life_xpm = mlx_load_xpm42("./imgs/life.xpm42");
	if (!life_xpm)
		exit(-4);
	life_img = mlx_texture_to_image(max->mlx, &life_xpm->texture);
	if (!life_img)
		exit(-8);

	y = 0;
	while (max->map->m[y + 1])
		y++;
	x = 0;
	max->maxlives = max->lives;
	while (x < max->lives)
	{
		if (mlx_image_to_window(max->mlx, life_img, x * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
			exit(-5);
		max->img->li = life_img->instances;
		x++;
	}
	mlx_delete_xpm42(life_xpm);
}