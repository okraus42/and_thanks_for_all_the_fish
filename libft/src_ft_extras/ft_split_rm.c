/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_rm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:57:11 by okraus            #+#    #+#             */
/*   Updated: 2023/07/16 13:04:00 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static void	ft_split_rm2(char **oldsplit, char **newsplit, int l, int n)
{
	int	i;

	i = 0;
	while (oldsplit[i] && i < n)
	{
		newsplit[i] = oldsplit[i];
		i++;
	}
	while (i < l)
	{
		newsplit[i] = oldsplit[i + 1];
		i++;
	}
}

int	ft_split_rm(char ***split, int n)
{
	int		l;
	char	**oldsplit;
	char	**newsplit;

	if (!split || !*split || n < 0)
		return (-1);
	oldsplit = *split;
	l = ft_splitlen(oldsplit);
	newsplit = malloc(sizeof(char *) * l);
	if (!newsplit || l <= n)
		return (-1);
	ft_split_rm2(oldsplit, newsplit, l, n);
	*split = newsplit;
	free(oldsplit);
	return (0);
}
