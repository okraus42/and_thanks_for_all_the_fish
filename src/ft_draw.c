/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:04:17 by okraus            #+#    #+#             */
/*   Updated: 2023/06/26 16:18:26 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

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
				if (mlx_image_to_window(max->mlx, wall_img, x * 32, y * 32) < 0)
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
				if (mlx_image_to_window(max->mlx, grnd_img, x * 32, y * 32) < 0)
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
