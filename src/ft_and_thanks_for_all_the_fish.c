/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_thanks_for_all_the_fish.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:35:23 by okraus            #+#    #+#             */
/*   Updated: 2023/06/27 16:13:50 by okraus           ###   ########.fr       */
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
	max->map->s = ft_itoa(max->map->steps);
	max->map->s = ft_strjoin_freeright("Steps: ", max->map->s);
	max->steps = mlx_put_string(max->mlx, max->map->s, 10, 10);
}

int	ft_and_thanks_for_all_the_fish(char *mapfile)
{
	mlx_t				*mlx;
	t_max				max;
	t_map				mapt;
	t_imgs				imgt;
	t_controls			keyt;

	max.map = &mapt;
	max.key = &keyt;
	max.img = &imgt;
	max.steps = NULL;
	ft_and_thanks_for_all_the_fish2(&max, mapfile);
	mlx = mlx_init(max.map->w * 32, max.map->h * 32, "AND THANX FOR ALL THE FISH", true);
	if (!max.mlx)
	{
		ft_printf_fd(2, "%s\n", mlx_strerror(mlx_errno));
		exit(-999);
	}
	max.mlx = mlx;
	ft_and_thanks_for_all_the_fish3(&max);
	mlx_loop_hook(mlx, ft_hook, &max);
	mlx_loop(mlx);
	if (mapt.p == -1)
	{
		ft_free(&max);
		mlx_terminate(mlx);
		return (0);
	}
	ft_free(&max);
	mlx_terminate(mlx);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc != 1)
	{
		ft_printf_fd(2, "%9CError%0C\n");
		return (1);
	}
	(void)argv;
	if (!ft_and_thanks_for_all_the_fish("maps/map1.ber"))
		if (!ft_and_thanks_for_all_the_fish("maps/map2.ber"))
			if (!ft_and_thanks_for_all_the_fish("maps/map3.ber"))
				ft_and_thanks_for_all_the_fish("maps/map4.ber");
	return (0);
}
