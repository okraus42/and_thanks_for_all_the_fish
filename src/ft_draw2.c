/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:16:15 by okraus            #+#    #+#             */
/*   Updated: 2023/06/26 16:20:26 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_put_collectibles3(t_max *max, mlx_image_t *col_img)
{
	int	x;
	int	y;

	y = 0;
	while (max->map->m[y])
	{
		x = 0;
		while (max->map->m[y][x])
		{
			if (max->map->m[y][x] == 'c')
			{
				if (mlx_image_to_window(max->mlx, col_img, x * 32, y * 32) < 0)
					exit(-5);
				max->img->ci = col_img->instances;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_collectibles(t_max *max)
{
	xpm_t		*col_xpm;
	mlx_image_t	*col_img;

	col_xpm = mlx_load_xpm42("./imgs/collectible1.xpm42");
	if (!col_xpm)
		exit(-4);
	col_img = mlx_texture_to_image(max->mlx, &col_xpm->texture);
	if (!col_img)
		exit(-8);
	ft_put_collectibles3(max, col_img);
	mlx_delete_xpm42(col_xpm);
}

void	ft_put_collectibles4(t_max *max, mlx_image_t *col2_img)
{
	int			x;
	int			y;

	y = 0;
	while (max->map->m[y])
	{
		x = 0;
		while (max->map->m[y][x])
		{
			if (max->map->m[y][x] == 'c')
			{
				if (mlx_image_to_window(max->mlx,
						col2_img, (max->map->w + x) * 32, y * 32) < 0)
					exit(-5);
				max->img->c2i = col2_img->instances;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_collectibles2(t_max *max)
{
	xpm_t		*col2_xpm;
	mlx_image_t	*col2_img;

	col2_xpm = mlx_load_xpm42("./imgs/collectible2.xpm42");
	if (!col2_xpm)
		exit(-4);
	col2_img = mlx_texture_to_image(max->mlx, &col2_xpm->texture);
	if (!col2_img)
		exit(-8);
	ft_put_collectibles4(max, col2_img);
	mlx_delete_xpm42(col2_xpm);
}
