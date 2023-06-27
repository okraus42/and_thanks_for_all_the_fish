/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:26:04 by okraus            #+#    #+#             */
/*   Updated: 2023/06/26 16:26:30 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_game(t_max *max)
{
	if ((max->key->w || max->key->a || max->key->s || max->key->d)
		&& !(max->key->t))
	{
		ft_moveplayer(max, max->key->w << 3 | max->key->s << 2
			| max->key->a << 1 | max->key->d);
		max->key->t++;
	}
	if (max->key->t && max->key->time)
	{
		ft_init_key(max->key, 0);
	}
	max->key->time++;
	if (max->key->t && max->key->t < 10)
	{
		max->key->t++;
	}
	else
	{
		max->key->t = 0;
	}
	if (max->key->time > 10)
	{
		max->key->time = 0;
	}
	ft_check_time(max);
}

void	ft_hook(void *param)
{
	t_max	*max;

	max = param;
	if (mlx_is_key_down(max->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(max->mlx);
	}
	if (max->map->p && mlx_is_key_down(max->mlx, MLX_KEY_UP))
	{
		ft_init_key(max->key, 1);
	}
	if (max->map->p && mlx_is_key_down(max->mlx, MLX_KEY_DOWN))
	{
		ft_init_key(max->key, 2);
	}
	if (max->map->p && mlx_is_key_down(max->mlx, MLX_KEY_LEFT))
	{
		ft_init_key(max->key, 3);
	}
	if (max->map->p && mlx_is_key_down(max->mlx, MLX_KEY_RIGHT))
	{
		ft_init_key(max->key, 4);
	}
	ft_game(max);
}
