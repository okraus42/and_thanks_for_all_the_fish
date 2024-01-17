/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:16:00 by okraus            #+#    #+#             */
/*   Updated: 2023/12/09 14:39:18 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	**ft_readfile(char *path, int size)
{
	int		fd;
	char	**file;
	char	*buff;
	int		r;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buff = ft_calloc(size + 1, sizeof(char));
	if (!buff)
		return (NULL);
	r = read(fd, buff, size);
	if (r <= 0 || r == size)
		return (NULL);
	close(fd);
	file = ft_split(buff, '\n');
	free(buff);
	return (file);
}
