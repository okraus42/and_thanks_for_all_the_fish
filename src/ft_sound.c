/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:15:57 by okraus            #+#    #+#             */
/*   Updated: 2023/11/11 13:19:56 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

int	ft_soundeffect(char **ev, char *track)
{
	pid_t	pid;
	char	*av[9];

	pid = fork();
	av[0] = "/usr/bin/ffplay";
	av[1] = "-v";
	av[2] = "-0";
	av[3] = "-nodisp";
	av[4] = "-autoexit";
	av[5] = "-loop";
	av[6] = "1";
	av[7] = track;
	av[8] = NULL;
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
	char	*av[9];

	pid = fork();
	av[0] = "/usr/bin/ffplay";
	av[1] = "-v";
	av[2] = "-0";
	av[3] = "-nodisp";
	av[4] = "-autoexit";
	av[5] = "-loop";
	av[6] = "0";
	av[7] = track;
	av[8] = NULL;
	if (pid == 0)
	{
		execve(av[0], av, ev);
		exit(0);
	}
	return (pid);
}