/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:37:57 by okraus            #+#    #+#             */
/*   Updated: 2023/08/17 14:57:06 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*read_file(int fd, char *str)
{
	char	*buff;
	int		r;

	r = 1;
	buff = malloc(sizeof(char) * (1 + 1));
	if (!buff)
		return (NULL);
	while (r > 0 && !ft_find_char(str, '\n'))
	{
		r = read(fd, buff, 1);
		if (r < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[r] = 0;
		str = ft_strjoin_gnl(str, buff);
	}
	free(buff);
	return (str);
}

char	*get(char *str)
{
	int		i;
	char	*gl;

	i = 0;
	if (!str || !str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	gl = malloc(sizeof(char) * (i + 2));
	if (!gl)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		gl[i] = str[i];
		i++;
	}
	gl[i] = str[i];
	gl[i + 1] = 0;
	return (gl);
}

char	*next(char *str)
{
	int		i;
	int		j;
	char	*nl;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (!str || !str[i])
	{
		free(str);
		return (NULL);
	}
	nl = malloc(sizeof(char) * (ft_strlen_gnl(str) + 1 - i));
	if (!nl)
		return (NULL);
	j = 0;
	i++;
	while (str[i + j])
	{
		nl[j] = str[i + j];
		j++;
	}
	nl[j] = 0;
	free (str);
	return (nl);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*nl;

	if (fd > 1023 || fd < 0 || 1 <= 0)
	{
		return (NULL);
	}
	if (!str[fd] || !ft_find_char(str[fd], '\n'))
	{
		str[fd] = read_file(fd, str[fd]);
	}
	nl = get(str[fd]);
	str[fd] = next(str[fd]);
	if (str[fd])
		free (str[fd]);
	str[fd] = NULL;
	return (nl);
}
