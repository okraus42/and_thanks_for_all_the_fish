/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_thanks_for_all_the_fish.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:35:23 by okraus            #+#    #+#             */
/*   Updated: 2023/06/29 09:42:46 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

void	ft_fill_map(t_map *map, char *mapfile)
{
	int		fd;
	char	*gamemap;
	char	*line;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		exit(-1);
	line = get_next_line(fd);
	gamemap = ft_strdup("");
	map->w = ft_strlen(line) - 1;
	while (line)
	{
		gamemap = ft_strjoin_freeleft(gamemap, line);
		free(line);
		line = get_next_line(fd);
		map->h++;
	}
	free(line);
	map->m = ft_split(gamemap, '\n');
	free(gamemap);
	ft_test_map(map);
}

void	ft_and_thanks_for_all_the_fish2(t_max *max, char *mapfile)
{
	ft_init_map(max->map);
	ft_init_keys(max->key);
	ft_fill_map(max->map, mapfile);
	ft_update_map(max->map);
}

void	ft_and_thanks_for_all_the_fish3(t_max *max)
{
	ft_put_background(max);
	ft_put_collectibles(max);
	ft_put_collectibles2(max);
	ft_put_opendoor(max);
	ft_put_door(max);
	ft_put_enemies(max);
	ft_put_player(max);
	max->map->cr = max->map->ct;
	max->key->time = 0;
	max->map->s = ft_itoa(max->score);
	max->map->s = ft_strjoin_freeright("Score: ", max->map->s);
	max->str = mlx_put_string(max->mlx, max->map->s, 10, 5);
	free(max->map->s);
	max->map->s = ft_itoa(max->time);
	max->map->s = ft_strjoin_freeright("Time left: ", max->map->s);
	max->tmp = mlx_put_string(max->mlx, max->map->s, 250, 5);
	mlx_delete_image(max->mlx, max->tmp);
}

int	ft_and_thanks_for_all_the_fish(char *mapfile, t_max *max)
{
	mlx_t				*mlx;
	t_map				mapt;
	t_imgs				imgt;
	t_controls			keyt;

	max->map = &mapt;
	max->key = &keyt;
	max->img = &imgt;
	max->str = NULL;
	max->tmp = NULL;
	ft_and_thanks_for_all_the_fish2(max, mapfile);
	mlx = mlx_init(max->map->w * 32, max->map->h * 32, "AND THANX FOR ALL THE FISH", true);
	if (!max->mlx)
	{
		ft_printf_fd(2, "%s\n", mlx_strerror(mlx_errno));
		exit(-999);
	}
	max->mlx = mlx;
	ft_and_thanks_for_all_the_fish3(max);
	mlx_loop_hook(mlx, ft_hook, max);
	mlx_loop(mlx);
	if (mapt.p == -1)
	{
		ft_free(max);
		mlx_terminate(mlx);
		return (0);
	}
	ft_free(max);
	mlx_terminate(mlx);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_max	max;

	max.score = 1000;
	max.time = 2000;
	if (argc != 1)
	{
		ft_printf_fd(2, "%9CError%0C\n");
		return (1);
	}
	(void)argv;
	if (!ft_and_thanks_for_all_the_fish("maps/map1.ber", &max))
		if (!ft_and_thanks_for_all_the_fish("maps/map2.ber", &max))
			if (!ft_and_thanks_for_all_the_fish("maps/map3.ber", &max))
				ft_and_thanks_for_all_the_fish("maps/map4.ber", &max);
	ft_printf("%93CFinal score: %i%0C\n", max.score);
	return (0);
}
