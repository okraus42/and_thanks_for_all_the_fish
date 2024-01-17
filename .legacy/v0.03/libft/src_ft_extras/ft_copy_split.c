/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:57:11 by okraus            #+#    #+#             */
/*   Updated: 2023/07/13 18:49:01 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	**ft_copy_split(char **split)
{
	int		i;
	int		l;
	char	**newsplit;

	i = 0;
	l = ft_splitlen(split) + 1;
	if (l < 0)
		return (NULL);
	newsplit = malloc(sizeof(char *) * l);
	while (split[i])
	{
		l = ft_strlen(split[i]) + 1;
		newsplit[i] = ft_calloc(sizeof(char), l);
		ft_strlcpy(newsplit[i], split[i], l);
		i++;
	}
	newsplit[i] = NULL;
	return (newsplit);
}
