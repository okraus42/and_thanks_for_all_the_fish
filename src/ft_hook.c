/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:26:04 by okraus            #+#    #+#             */
/*   Updated: 2023/11/19 11:24:39 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

static void	ft_putscore(t_max *max)
{
	char *str;

	max->time -= max->key->mspf;
	free (max->map->s);
	if (!max->key->mspf)
		max->key->mspf = 1000;
	max->map->s = ft_itoa(1000 / max->key->mspf);
	max->map->s = ft_strjoin_freeright("        FPS: ", max->map->s);
	str = ft_itoa(max->time / 1000);
	max->map->s = ft_strjoin_freeright(str, max->map->s);
	free(str);
	max->map->s = ft_strjoin_freeright("        Time left: ", max->map->s);
	str = ft_itoa(max->score);
	max->map->s = ft_strjoin_freeright(str, max->map->s);
	free(str);
	max->map->s = ft_strjoin_freeright("Score: ", max->map->s);
	mlx_delete_image(max->mlx, max->str);
	max->str = mlx_put_string(max->mlx, max->map->s, 10, 5);
	if (max->time <= 0)
	{
		ft_printf("%14.*^*CYou have run out of time :/%C\n", 0xFFFFFF, 0x880000);
		ft_printf("%25.*^*CCurrent score: %i%C\n", 0xFFFFFF, 0x888800, max->score);
		max->map->p = 0; 
		max->lives = 0;
		//mlx_close_window(max->mlx);
	}
}

// static void	ft_puttime(t_max *max)
// {
// 	max->time--;
// 	free (max->map->s);
// 	max->map->s = ft_itoa(max->time);
// 	max->map->s = ft_strjoin_freeright("Time left: ", max->map->s);
// 	mlx_delete_image(max->mlx, max->tmp);
// 	max->tmp = mlx_put_string(max->mlx, max->map->s, 250, 5);
// 	f
	
// }

void	ft_game(t_max *max)
{
	if ((max->key->w || max->key->a || max->key->s || max->key->d)
		&& !(max->key->mt))
	{
		ft_moveplayer(max, max->key->w << 3 | max->key->s << 2
			| max->key->a << 1 | max->key->d);
		max->key->mt = max->key->mspf;
	}
	if (max->key->mt)
	{
		ft_init_key(max->key, 0);
	}
	max->key->time++;
	max->score -= max->key->mspf;
	if (max->key->mt && max->key->mt < 256)
	{
		max->key->t++;
		max->key->mt += max->key->mspf;
	}
	else
	{
		max->key->mt = 0;
	}
	if (max->key->time > 20)
	{
		max->key->time = 0;	
	}
	ft_putscore(max);
	ft_update_gametime_in_ms(max);
	ft_check_time(max);
}

void	ft_pause(t_max *max)
{
	static int time = 0;

	if (time < 1000)
		time += max->key->mspf;
	else
	{
		time = 0;
		mlx_close_window(max->mlx);
	}
}

void	ft_hook(void *param)
{
	t_max	*max;

	max = param;
	if (mlx_is_key_down(max->mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("%14.*^*CYou have quit the game:/%0C\n", 0xFFFFFF, 0x880000);
		ft_printf("%25.*^*CCurrent score: %i%C\n", 0xFFFFFF, 0x888800, max->score);
		max->exit = 1;
		mlx_close_window(max->mlx);
	}
	if (mlx_is_key_down(max->mlx, MLX_KEY_KP_SUBTRACT))
	{
		ft_printf("%25.*^*C%s is a cheater!!!/%0C\n", 0xFFFFFF, 0x880088, max->player_name);
		free(max->player_name);
		max->player_name = ft_strdup("cheater");
		if (!max->player_name)
			exit(5);
		mlx_close_window(max->mlx);
	}
	if (mlx_is_key_down(max->mlx, MLX_KEY_KP_MULTIPLY))
	{
		ft_printf("%25.*^*C%s is a cheater!!!/%0C\n", 0xFFFFFF, 0x880088, max->player_name);
		max->time += 60000;
		max->score += 100000;
		max->lives += 1;
		max->death = 1;
		free(max->player_name);
		max->player_name = ft_strdup("cheater");
		if (!max->player_name)
			exit(5);
		mlx_close_window(max->mlx);
	}
	// if (max->map->p < 0 && mlx_is_key_down(max->mlx, MLX_KEY_ENTER))
	// {
	// 	mlx_close_window(max->mlx);
	// }
	if (max->map->p > 0 && mlx_is_key_down(max->mlx, MLX_KEY_UP))
	{
		ft_init_key(max->key, UP);
	}
	if (max->map->p > 0 && mlx_is_key_down(max->mlx, MLX_KEY_DOWN))
	{
		ft_init_key(max->key, DOWN);
	}
	if (max->map->p > 0 && mlx_is_key_down(max->mlx, MLX_KEY_LEFT))
	{
		ft_init_key(max->key, LEFT);
	}
	if (max->map->p > 0 && mlx_is_key_down(max->mlx, MLX_KEY_RIGHT))
	{
		ft_init_key(max->key, RIGHT);
	}
	if (max->map->p > 0)
		ft_game(max);
	else
		ft_pause(max);
}
