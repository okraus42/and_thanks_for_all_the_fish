/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:17:59 by okraus            #+#    #+#             */
/*   Updated: 2023/11/11 16:17:41 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

void	ft_put_enemies_left2(t_max *max, mlx_image_t *en_img)
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
				if (mlx_image_to_window(max->mlx, en_img, x * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
					exit(-5);
				max->img->eli = en_img->instances;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_enemies_left(t_max *max)
{
	xpm_t		*en_xpm;
	mlx_image_t	*en_img;

	en_xpm = mlx_load_xpm42("./imgs/EL.xpm42");
	if (!en_xpm)
		exit(-4);
	en_img = mlx_texture_to_image(max->mlx, &en_xpm->texture);
	if (!en_img)
		exit(-8);
	ft_put_enemies_left2(max, en_img);
	mlx_delete_xpm42(en_xpm);
}

void	ft_put_enemies_right2(t_max *max, mlx_image_t *en_img)
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
				if (mlx_image_to_window(max->mlx, en_img, (max->map->w + x) * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
					exit(-5);
				max->img->eri = en_img->instances;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_enemies_right(t_max *max)
{
	xpm_t		*en_xpm;
	mlx_image_t	*en_img;

	en_xpm = mlx_load_xpm42("./imgs/ER.xpm42");
	if (!en_xpm)
		exit(-4);
	en_img = mlx_texture_to_image(max->mlx, &en_xpm->texture);
	if (!en_img)
		exit(-8);
	ft_put_enemies_right2(max, en_img);
	mlx_delete_xpm42(en_xpm);
}

void	ft_put_enemies_up2(t_max *max, mlx_image_t *en_img)
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
				if (mlx_image_to_window(max->mlx, en_img, (max->map->w + x) * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
					exit(-5);
				max->img->eui = en_img->instances;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_enemies_up(t_max *max)
{
	xpm_t		*en_xpm;
	mlx_image_t	*en_img;

	en_xpm = mlx_load_xpm42("./imgs/EU.xpm42");
	if (!en_xpm)
		exit(-4);
	en_img = mlx_texture_to_image(max->mlx, &en_xpm->texture);
	if (!en_img)
		exit(-8);
	ft_put_enemies_up2(max, en_img);
	mlx_delete_xpm42(en_xpm);
}

void	ft_put_enemies_down2(t_max *max, mlx_image_t *en_img)
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
				if (mlx_image_to_window(max->mlx, en_img, (max->map->w + x) * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
					exit(-5);
				max->img->edi = en_img->instances;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_enemies_down(t_max *max)
{
	xpm_t		*en_xpm;
	mlx_image_t	*en_img;

	en_xpm = mlx_load_xpm42("./imgs/ED.xpm42");
	if (!en_xpm)
		exit(-4);
	en_img = mlx_texture_to_image(max->mlx, &en_xpm->texture);
	if (!en_img)
		exit(-8);
	ft_put_enemies_down2(max, en_img);
	mlx_delete_xpm42(en_xpm);
}

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
				if (mlx_image_to_window(max->mlx, en_img, x * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
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
	ft_put_enemies_left(max);
	ft_put_enemies_right(max);
	ft_put_enemies_up(max);
	ft_put_enemies_down(max);
}

void	ft_put_player_left2(t_max *max, mlx_image_t *play_img)
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
				if (mlx_image_to_window(max->mlx, play_img, (max->map->w + x) * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
					exit(-5);
				max->img->pli = play_img->instances;
				max->map->px = x;
				max->map->py = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_player_left(t_max *max)
{
	xpm_t		*play_xpm;
	mlx_image_t	*play_img;

	play_xpm = mlx_load_xpm42("./imgs/PL.xpm42");
	if (!play_xpm)
		exit(-4);
	play_img = mlx_texture_to_image(max->mlx, &play_xpm->texture);
	if (!play_img)
		exit(-8);
	ft_put_player_left2(max, play_img);
	mlx_delete_xpm42(play_xpm);
}

void	ft_put_player_right2(t_max *max, mlx_image_t *play_img)
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
				if (mlx_image_to_window(max->mlx, play_img, x * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
					exit(-5);
				max->img->pri = play_img->instances;
				max->map->px = x;
				max->map->py = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_player_right(t_max *max)
{
	xpm_t		*play_xpm;
	mlx_image_t	*play_img;

	play_xpm = mlx_load_xpm42("./imgs/PR.xpm42");
	if (!play_xpm)
		exit(-4);
	play_img = mlx_texture_to_image(max->mlx, &play_xpm->texture);
	if (!play_img)
		exit(-8);
	ft_put_player_right2(max, play_img);
	mlx_delete_xpm42(play_xpm);
}

void	ft_put_player_up2(t_max *max, mlx_image_t *play_img)
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
				if (mlx_image_to_window(max->mlx, play_img, (max->map->w + x) * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
					exit(-5);
				max->img->pui = play_img->instances;
				max->map->px = x;
				max->map->py = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_player_up(t_max *max)
{
	xpm_t		*play_xpm;
	mlx_image_t	*play_img;

	play_xpm = mlx_load_xpm42("./imgs/PU.xpm42");
	if (!play_xpm)
		exit(-4);
	play_img = mlx_texture_to_image(max->mlx, &play_xpm->texture);
	if (!play_img)
		exit(-8);
	ft_put_player_up2(max, play_img);
	mlx_delete_xpm42(play_xpm);
}

void	ft_put_player_down2(t_max *max, mlx_image_t *play_img)
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
				if (mlx_image_to_window(max->mlx, play_img, (max->map->w + x) * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
					exit(-5);
				max->img->pdi = play_img->instances;
				max->map->px = x;
				max->map->py = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_player_down(t_max *max)
{
	xpm_t		*play_xpm;
	mlx_image_t	*play_img;

	play_xpm = mlx_load_xpm42("./imgs/PD.xpm42");
	if (!play_xpm)
		exit(-4);
	play_img = mlx_texture_to_image(max->mlx, &play_xpm->texture);
	if (!play_img)
		exit(-8);
	ft_put_player_down2(max, play_img);
	mlx_delete_xpm42(play_xpm);
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
				if (mlx_image_to_window(max->mlx, play_img, x * BLOCK_WIDTH, y * BLOCK_HEIGHT) < 0)
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
	ft_put_player_left(max);
	ft_put_player_right(max);
	ft_put_player_up(max);
	ft_put_player_down(max);
}
