/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:16:05 by okraus            #+#    #+#             */
/*   Updated: 2023/09/12 08:38:57 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

void	ft_put_door2(t_max *max, mlx_image_t *door_img)
{
	int			x;
	int			y;

	y = 0;
	while (max->map->m[y])
	{
		x = 0;
		while (max->map->m[y][x])
		{
			if (max->map->m[y][x] == 'e')
			{
				if (mlx_image_to_window(max->mlx, door_img, x * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
					exit(-5);
				max->img->dci = door_img->instances;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_door(t_max *max)
{
	xpm_t		*door_xpm;
	mlx_image_t	*door_img;

	door_xpm = mlx_load_xpm42("./imgs/door.xpm42");
	if (!door_xpm)
		exit(-4);
	door_img = mlx_texture_to_image(max->mlx, &door_xpm->texture);
	if (!door_img)
		exit(-8);
	ft_put_door2(max, door_img);
	mlx_delete_xpm42(door_xpm);
}

void	ft_put_opendoor2(t_max *max, mlx_image_t *opendoor_img)
{
	int			x;
	int			y;

	y = 0;
	while (max->map->m[y])
	{
		x = 0;
		while (max->map->m[y][x])
		{
			if (max->map->m[y][x] == 'e')
			{
				if (mlx_image_to_window(max->mlx,
						opendoor_img, x * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
					exit(-5);
				max->img->doi = opendoor_img->instances;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_opendoor(t_max *max)
{
	xpm_t		*opendoor_xpm;
	mlx_image_t	*opendoor_img;

	opendoor_xpm = mlx_load_xpm42("./imgs/dooropen.xpm42");
	if (!opendoor_xpm)
		exit(-4);
	opendoor_img = mlx_texture_to_image(max->mlx, &opendoor_xpm->texture);
	if (!opendoor_img)
		exit(-8);
	ft_put_opendoor2(max, opendoor_img);
	mlx_delete_xpm42(opendoor_xpm);
}
