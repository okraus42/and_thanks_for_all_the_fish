/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:02:27 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:13:50 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static size_t	ft_strtrimfs(char const *s1, char const *set)
{
	size_t	start;
	size_t	i;
	size_t	j;

	start = 0;
	i = 0;
	j = 0;
	if (s1[0] == 0)
		return (1);
	while (s1 && start == j)
	{
		i = 0;
		while (set[i])
		{
			if (set[i] == s1[j])
			{
				start++;
				i++;
				break ;
			}
			i++;
		}
		j++;
	}
	return (start);
}

static size_t	ft_strtrimfe(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	size_t	j;

	j = ft_strlen(s1) - 1;
	end = j;
	i = 0;
	if (s1[0] == 0)
		return (0);
	while (end && end == j)
	{
		i = 0;
		while (set[i])
		{
			if (set[i] == s1[j])
				end--;
			i++;
		}
		j--;
	}
	return (end);
}

static size_t	ft_strtrimnl(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	newlen;

	start = ft_strtrimfs(s1, set);
	end = ft_strtrimfe(s1, set);
	newlen = end - start + 1;
	if (end < start)
		return (0);
	return (newlen);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	newlen;
	size_t	start;
	size_t	i;
	char	*s2;

	newlen = ft_strtrimnl(s1, set);
	start = ft_strtrimfs(s1, set);
	s2 = (char *)malloc((newlen + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < newlen)
	{
		s2[i] = s1[i + start];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
