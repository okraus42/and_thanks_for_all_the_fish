/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_thanks_for_all_the_fish.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:35:23 by okraus            #+#    #+#             */
/*   Updated: 2023/09/21 11:55:30 by okraus           ###   ########.fr       */
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
	ft_put_lives(max);
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
	max->death = 0;
	max->str = NULL;
	max->tmp = NULL;
	ft_and_thanks_for_all_the_fish2(max, mapfile);
	mlx_set_setting(MLX_FULLSCREEN, true);
	mlx = mlx_init(max->map->w * BLOCK_WIDTH, max->map->h * BLOCK_HEIGHT, "AND THANX FOR ALL THE FISH", true);
	if (!mlx)
	{
		ft_printf_fd(2, "%s\n", mlx_strerror(mlx_errno));
		exit(-9);
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

int	ft_check_printable(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i + 1])
	{
		if (!ft_isprint(str[i]))
			return (0);
		++i;
	}
	return (1);
}

char	*ft_printmove(char *str)
{
	int		i;
	int		l;
	char	*print;

	if (!str)
		return (NULL);
	i = 0;
	l = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
			l++;
		i++;
	}
	print = ft_calloc(l + 1, sizeof(char));
	if (!print)
		return (NULL);
	i = 0;
	l = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
		{
			print[l] = str[i];
			l++;
		}
		i++;
	}
	free(str);
	return (print);
}

void	ft_max_init(t_max *max)
{
	char	*str;
	char	*yn;
	char	*coal;

	max->score = 2500;
	max->time = 2500;
	max->exit = 0;
	max->death = 1;
	max->lives = 1;
	str = NULL;
	yn = NULL;
	coal = NULL;
	ft_printf("Press Enter to continue:");
	free(get_next_line(0));
	while (!str)
	{
		ft_printf("Enter your intra name or type 'exit' to quit: \n");
		str = ft_printmove(get_next_line(0));
		if (!str || ft_strlen(str) > 15 || ft_strlen(str) < 3 || ft_strchr(str, ':'))
		{
			ft_printf_fd(2, "%s: Invalid name! \nUse between 3-15 characters and avoid ':'\n", str);
			free(str);
			str = NULL;
		}
		while (str && ft_strncmp(str, "exit", 5))
		{
			ft_printf("\nIs your name: %s?\nPress 'y' to continue\n", str);
			yn = get_next_line(0);
			if (yn && (yn[0] == 'y' || yn[0] == 'Y'))
			{
				free(yn);
				break;
			}
			else
			{
				if (yn)
					free(yn);
				yn = NULL;
				if (str)
					free(str);
				str = NULL;
			}
		}
	}
	max->player_name = str;
	if (!ft_strncmp(max->player_name, "exit", 5))
		max->exit = 1;
	str = NULL;
	yn = NULL;
	while (!max->exit && !str)
	{
		ft_printf("\nChoose your coalition: \n1 - Alderaan   2 - Naboo   3 - Tatooine   4 - Mandalore   5 - other\n");
		coal = ft_printmove(get_next_line(0));
		if (!coal)
		{
			max->exit = 1;
			break;
		}
		if (coal[0] == '1')
			str = ft_stringcopy(ALDERAAN);
		else if (coal[0] == '2')
			str = ft_stringcopy(NABOO);
		else if (coal[0] == '3')
			str = ft_stringcopy(TATOOINE);
		else if (coal[0] == '4')
			str = ft_stringcopy(MANDALORE);
		else if (coal[0] == '5')
		{
			ft_printf("\nType the name of your coalition\n");
			str = ft_printmove(get_next_line(0));
			if (!str  || ft_strlen(str) > 15 || ft_strlen(str) < 3 || ft_strchr(str, ':'))
			{
				ft_printf_fd(2, "%s: Invalid name! \nUse between 3-15 characters and avoid ':'\n", str);
				free(str);
				str = NULL;
			}
			while (str && ft_strncmp(str, "exit", 5))
			{
				ft_printf("\nIs your coalition: %s?\nPress 'y' to continue\n", str);
				yn = get_next_line(0);
				if (yn && (yn[0] == 'y' || yn[0] == 'Y'))
				{
					free(yn);
					break;
				}
				else
				{
					if (yn)
						free(yn);
					yn = NULL;
					if (str)
						free(str);
					str = NULL;
				}
			}
		}
		else
			continue;
		
	}
	max->player_coalition = str;
}

void	ft_print_score(t_list *lst)
{
	t_hs	*tmp;
	int		i;

	i = 1;
	ft_printf("%68CPosition   |                Name   |           Coalition   |  Score %0C\n");
	while (lst && i <= 25)
	{
		tmp = lst->content;
		if (!ft_strncmp(tmp->coalition, NABOO, 10))
			ft_printf("%54C");
		else if (!ft_strncmp(tmp->coalition, ALDERAAN, 10))
			ft_printf("%43C");
		else if (!ft_strncmp(tmp->coalition, TATOOINE, 10))
			ft_printf("%53C");
		else if (!ft_strncmp(tmp->coalition, MANDALORE, 10))
			ft_printf("%51C");
		else
			ft_printf("%58C");
		ft_printf("     %3i   |", i);
		ft_printf("%20s   |", tmp->name);
		ft_printf("%20s   |", tmp->coalition);
		ft_printf("%7i", tmp->score);
		ft_printf("%0C\n");
		lst = lst->next;
		++i;
	}
}

int	ft_sortscore(t_list *lst)
{
	t_hs	*now;
	t_hs	*next;
	int		r;

	r = 0;
	while (lst && lst->next)
	{
		now = lst->content;
		next = lst->next->content;
		if (now->score < next->score)
		{
			lst->next->content = now;
			lst->content = next;
			r = 1;
		}
		lst = lst->next;
	}
	return (r);
}

void	ft_highscore(int fd)
{
	t_hs	*tmp;
	t_list	*head;
	t_list	*leaf;
	char	*str;
	int		i;
	int		zero[3];

	i = 0;

	head = NULL;
	str = get_next_line(fd);
	while (str)
	{
		tmp = malloc(sizeof(t_hs));
		if (!tmp)
			exit(2);
		tmp->index = i;
		zero[0] = 0;
		while(str && str[zero[0]] != ':')
			zero[0]++;
		str[zero[0]] = '\0';
		zero[1] = zero[0] + 1;
		while(str && str[zero[1]] != ':')
			zero[1]++;
		str[zero[1]] = '\0';
		zero[2] = zero[1] + 1;
		while(str && str[zero[2]] != '\n')
			zero[2]++;
		str[zero[2]] = '\0';
		tmp->score = ft_atoi(&str[zero[1] + 1]);
		tmp->name = ft_stringcopy(str);
		if (!tmp->name)
			exit(2);
		tmp->coalition = ft_stringcopy(&str[zero[0] + 1]);
		if (!tmp->coalition)
			exit(2);
		leaf = ft_lstnew(tmp);
		if (!leaf)
			exit(2);
		ft_lstadd_back(&head, leaf);
		i++;
		free(str);
		str = NULL;
		str = get_next_line(fd);
	}
	while (ft_sortscore(head))
		continue;
	ft_print_score(head);
}

int	main(int argc, char *argv[])
{
	t_max	max;
	int		fd;

	ft_max_init(&max);
	if (argc != 1)
	{
		ft_printf_fd(2, "%9CError%0C\n");
		return (1);
	}
	(void)argv;
	while (!max.exit)
	{
		fd = open("score.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd < 0)
			return (1);
		while (max.death && max.lives && !max.exit)
			ft_and_thanks_for_all_the_fish("maps/map1.ber", &max);
		max.death++;
			while (max.death && max.lives && !max.exit)
			ft_and_thanks_for_all_the_fish("maps/map2.ber", &max);
		max.death++;
		while (max.death && max.lives && !max.exit)
			ft_and_thanks_for_all_the_fish("maps/map3.ber", &max);
		max.death++;
		while (max.death && max.lives && !max.exit)
			ft_and_thanks_for_all_the_fish("maps/map4.ber", &max);
		max.death++;
		while (max.death && max.lives && !max.exit)
			ft_and_thanks_for_all_the_fish("maps/map5.ber", &max);
		ft_printf("%93CFinal score: %i%0C\n", max.score);
		ft_printf_fd(fd, "%s:%s:%i\n", max.player_name, max.player_coalition, max.score);
		free(max.player_name);
		free(max.player_coalition);
		close(fd);
		fd = open("score.txt", O_RDONLY);
		if (fd < 0)
			return (1);
		ft_highscore(fd);
		close (fd);
		ft_max_init(&max);
	}
	free(max.player_name);
	free(max.player_coalition);
	return (0);
}
