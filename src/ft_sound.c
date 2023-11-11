/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:15:57 by okraus            #+#    #+#             */
/*   Updated: 2023/11/11 11:30:13 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

int	ft_soundeffect(char **ev, char *track)
{
	pid_t	pid;
	char	*av[4];

	pid = fork();
	av[0] = "/usr/bin/mpg123";
	av[1] = "-q";
	av[2] = track;
	av[3] = NULL;
	if (pid == 0)
	{
		execve(av[0], av, ev);
		exit(0);
	}
	return (pid);
}
	
int	ft_soundmusic(char **ev, char *track)
{
	pid_t	pid;
	char	*av[6];

	pid = fork();
	av[0] = "/usr/bin/mpg123";
	av[1] = "-q";
	av[2] = "--loop";
	av[3] = "-1";
	av[4] = track;
	av[5] = NULL;
	if (pid == 0)
	{
		execve(av[0], av, ev);
		exit(0);
	}
	return (pid);
}