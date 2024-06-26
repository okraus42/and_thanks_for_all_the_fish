/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:15:57 by okraus            #+#    #+#             */
/*   Updated: 2024/03/21 17:18:44 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

int	ft_soundeffect(char **ev, char *track, int vol)
{
	pid_t	pid;
	char	*av[11];
	int		fd;
	char	volume[50];

	ft_snprintf(volume, 40, "volume=%.2^8P", vol);
	//ft_printf("TRACK VOLUME %s %s %i\n", track, volume, vol); 
	pid = fork();
	av[0] = "/usr/bin/ffplay";
	av[1] = "-v";
	av[2] = "-0";
	av[3] = "-nodisp";
	av[4] = "-autoexit";
	av[5] = "-loop";
	av[6] = "1";
	av[7] = track;
	av[8] = "-af";
	av[9] = volume;
	av[10] = NULL;
	//ft_put_split(av);
	if (pid == 0)
	{
		fd = open("/dev/null", O_WRONLY);
		dup2(fd, 1);
		dup2(fd, 2);
		close(fd);
		execve(av[0], av, ev);
		exit(9);
	}
	return (pid);
}
	
int	ft_soundmusic(char **ev, char *track, int vol)
{
	pid_t	pid;
	char	*av[11];
	int		fd;
	char	volume[50];

	ft_snprintf(volume, 40, "volume=%.2^8P", vol);
	//ft_printf("%s %s\n", track, volume); 
	pid = fork();
	av[0] = "/usr/bin/ffplay";
	av[1] = "-v";
	av[2] = "-0";
	av[3] = "-nodisp";
	av[4] = "-autoexit";
	av[5] = "-loop";
	av[6] = "0";
	av[7] = track;
	av[8] = "-af";
	av[9] = volume;
	av[10] = NULL;
	if (pid == 0)
	{
		fd = open("/dev/null", O_WRONLY);
		dup2(fd, 1);
		dup2(fd, 2);
		close(fd);
		execve(av[0], av, ev);
		exit(9);
	}
	return (pid);
}