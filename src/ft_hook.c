/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:26:04 by okraus            #+#    #+#             */
/*   Updated: 2023/09/17 15:24:20 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

static void	ft_putscore(t_max *max)
{
	char *str;

	max->time--;
	free (max->map->s);
	max->map->s = ft_itoa(max->time);
	max->map->s = ft_strjoin_freeright("        Time left: ", max->map->s);
	str = ft_itoa(max->score);
	max->map->s = ft_strjoin_freeright(str, max->map->s);
	free(str);
	max->map->s = ft_strjoin_freeright("Score: ", max->map->s);
	mlx_delete_image(max->mlx, max->str);
	max->str = mlx_put_string(max->mlx, max->map->s, 10, 5);
	if (max->score <= 0)
	{
		ft_printf("%41CYour score have dropped to 0 :/%0C\n");
		ft_printf("%55CCurrent score: %i%0C\n", max->score);
		mlx_close_window(max->mlx);
	}
	if (max->time <= 0)
	{
		ft_printf("%41CYou have run out of time :/%0C\n");
		ft_printf("%55CCurrent score: %i%0C\n", max->score);
		mlx_close_window(max->mlx);
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
	max->score--;
	if (max->key->t && max->key->t < 10)
	{
		max->key->t++;
	}
	else
	{
		max->key->t = 0;
	}
	if (max->key->time > 20)
	{
		max->key->time = 0;	
	}
	ft_putscore(max);
	ft_check_time(max);
}

void	ft_hook(void *param)
{
	t_max	*max;

	max = param;
	if (mlx_is_key_down(max->mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("%41CYou have quit the game:/%0C\n");
		ft_printf("%55CCurrent score: %i%0C\n", max->score);
		max->exit = 1;
		mlx_close_window(max->mlx);
	}
	if (mlx_is_key_down(max->mlx, MLX_KEY_KP_SUBTRACT))
	{
		ft_printf("%41C%s is a cheater!!!/%0C\n", max->player_name);
		free(max->player_name);
		max->player_name = ft_strdup("cheater");
		if (!max->player_name)
			exit(5);
		mlx_close_window(max->mlx);
	}
	if (mlx_is_key_down(max->mlx, MLX_KEY_KP_MULTIPLY))
	{
		ft_printf("%41C%s is a cheater!!!/%0C\n", max->player_name);
		max->time += 5000;
		max->score += 2500;
		max->lives += 1;
		max->death = 1;
		free(max->player_name);
		max->player_name = ft_strdup("cheater");
		if (!max->player_name)
			exit(5);
		mlx_close_window(max->mlx);
	}
	if (max->map->p < 0 && mlx_is_key_down(max->mlx, MLX_KEY_ENTER))
	{
		mlx_close_window(max->mlx);
	}
	if (max->map->p > 0 && mlx_is_key_down(max->mlx, MLX_KEY_UP))
	{
		ft_init_key(max->key, 1);
	}
	if (max->map->p > 0 && mlx_is_key_down(max->mlx, MLX_KEY_DOWN))
	{
		ft_init_key(max->key, 2);
	}
	if (max->map->p > 0 && mlx_is_key_down(max->mlx, MLX_KEY_LEFT))
	{
		ft_init_key(max->key, 3);
	}
	if (max->map->p > 0 && mlx_is_key_down(max->mlx, MLX_KEY_RIGHT))
	{
		ft_init_key(max->key, 4);
	}
	ft_game(max);
}
