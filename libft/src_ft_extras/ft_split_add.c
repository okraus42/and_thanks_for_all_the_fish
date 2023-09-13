/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:57:11 by okraus            #+#    #+#             */
/*   Updated: 2023/08/13 15:37:24 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static void	ft_split_add2(char **oldsplit, char **newsplit, int l, int n)
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
		newsplit[i + 1] = oldsplit[i];
		i++;
	}
}

static char	*ft_split_add3(char *s)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}

int	ft_split_add(char ***split, char *s, int n)
{
	int		l;
	char	**oldsplit;
	char	**newsplit;

	if (!split || !*split || !s)
	{
		ft_printf_fd(2, "ft_split_add: Invalid input\n");
		return (-1);
	}
	oldsplit = *split;
	l = ft_splitlen(oldsplit) + 1;
	newsplit = malloc(sizeof(char *) * (l + 1));
	if (!newsplit || l <= n)
	{
		ft_printf_fd(2, "ft_split_add: Malloc fail or incorrect size\n");
		return (-1);
	}
	ft_split_add2(oldsplit, newsplit, l, n);
	newsplit[n] = ft_split_add3(s);
	*split = newsplit;
	free(oldsplit);
	return (0);
}
