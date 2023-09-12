/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:02:36 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:13:33 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_check_separator(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	ft_count_strings(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && ft_check_separator(s[i], c))
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && !ft_check_separator(s[i], c))
			i++;
	}
	return (count);
}

static int	ft_strlen_sep(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !ft_check_separator(s[i], c))
		i++;
	return (i);
}

static char	*ft_word(char *s, char c)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_strlen_sep(s, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**ss;
	int		i;
	int		j;

	j = 0;
	i = 0;
	ss = (char **)malloc(sizeof(char *) * (ft_count_strings((char *)s, c) + 1));
	if (ss == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		while (s[j] != '\0' && ft_check_separator(s[j], c))
			j++;
		if (s[j] != '\0')
		{
			ss[i] = ft_word(&((char *)s)[j], c);
			i++;
		}
		while (s[j] && !ft_check_separator(s[j], c))
			j++;
	}
	ss[i] = 0;
	return (ss);
}
