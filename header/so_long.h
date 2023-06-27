/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:43:08 by okraus            #+#    #+#             */
/*   Updated: 2023/06/26 16:28:57 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

// INCLUDES

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <sys/wait.h> //check if needed, but it must be
# include <time.h> //check if needed
# include <sys/types.h> //open function1
# include <sys/stat.h> //open function2
# include <fcntl.h> //open function3
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/header/libft.h"

// DEFINITIONS

// STRUCTURES
// SO_LONG structure

// typedef struct map_s
// {
// 	char	**m;		//map saved in array
// 	int		w;			//width of map
// 	int		h;			//height of map
// 	int		p;			//player status 1-alive, 0 dead
// 	int		px;			//player position on map the x axis
// 	int		py;			//player position on map the y axis
//						//add player direction?
// 	int		ct;			//total number of collectibles
//	int		cr;			//number of remaining collectibles
// 	int		*c;			//collectible status 
// 	int		*cx;		//collectible position on the x axis
// 	int		*cy;		//collectible position on the y axis
// 	int		et;			//total number of enemies
//						//add enemy remaining?
// 	int		*e;			//array of enemies 0 dead, 1 alive
// 	int		*ex;		//enemy position on map the x axis
// 	int		*ey;		//enemy position on map the y axis
//						//add enemy direction?
//	int		x;			// exit status 0 closed, 1 open
//	int		xx;			// exit X
//	int		xy;			// exit Y
//	int		steps;		// number of steps player did
// } map_t;

typedef struct s_map
{
	char	**m;
	char	*s;
	int		w;
	int		h;
	int		p;
	int		px;
	int		py;
	int		ct;
	int		cr;
	int		*c;
	int		*cx;
	int		*cy;
	int		et;
	int		*e;
	int		*ex;
	int		*ey;
	int		x;
	int		xx;
	int		xy;
	int		steps;
}	t_map;

typedef struct s_control
{
	int		w;
	int		s;
	int		a;
	int		d;
	int		space;
	int		ctrl;
	int		time;
	int		t;
}	t_controls;

typedef struct s_imgs
{
	mlx_instance_t	*pi;
	mlx_instance_t	*ei;
	mlx_instance_t	*ci;
	mlx_instance_t	*c2i;
	mlx_instance_t	*dci;
	mlx_instance_t	*doi;
}	t_imgs;

typedef struct s_max
{
	mlx_t		*mlx;
	t_map		*map;
	t_controls	*key;
	t_imgs		*img;
	mlx_image_t	*steps;
}	t_max;

// PROTOTYPES

//	ft_draw
void	ft_put_background(t_max *max);
//	ft_draw2
void	ft_put_collectibles(t_max *max);
void	ft_put_collectibles2(t_max *max);
//	ft_draw3
void	ft_put_opendoor(t_max *max);
void	ft_put_door(t_max *max);
//	ft_draw4
void	ft_put_enemies(t_max *max);
void	ft_put_player(t_max *max);

//	ft_hook
void	ft_hook(void *param);
void	ft_game(t_max *max);

//	ft_player
void	ft_moveplayer(t_max *max, int d);

//	ft_enemy
void	ft_moveenemies(t_max *max);

//	ft_check_enemy
void	ft_check_enemy(t_max *max);
int		ft_checkmovee(t_map *map, int i, int x, int y);
void	ft_domovee(t_max *max, int i, int d);

// ft_collectible
void	ft_remove_collectible(t_max *max, int x, int y);
void	ft_open_door(t_max *max);
void	ft_check_door(t_max *max);
void	ft_check_time(t_max *max);

//	ft_init
void	ft_flood_map(t_map *map, int x, int y);
void	ft_init_key(t_controls *key, int a);
void	ft_init_map(t_map *map);
void	ft_init_keys(t_controls *key);

//	ft_update
void	ft_update_map(t_map *map);

//	ft_test
void	ft_test_map(t_map *map);
void	ft_check_map(t_map *map);
void	ft_check_flood(t_map *map);
void	ft_print_map(t_map *map);

//	ft_free
void	ft_free(t_max *max);
void	ft_exit(t_map *map, int n);

#endif
