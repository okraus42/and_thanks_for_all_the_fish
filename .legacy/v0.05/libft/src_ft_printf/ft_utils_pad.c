/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:31:44 by okraus            #+#    #+#             */
/*   Updated: 2023/10/13 17:37:02 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_padleft(int i, char c, char **s)
{
	char	*str;

	str = malloc(i + 1);
	if (!str)
		return (1);
	str[i] = 0;
	str = ft_memset(str, c, i);
	str[i] = 0;
	*s = ft_strjoin_freeboth(str, *s);
	if (!*s)
		return (1);
	return (0);
}

int	ft_padright(int i, char c, char **s)
{
	char	*str;

	str = malloc(i + 1);
	if (!str)
		return (1);
	str[i] = 0;
	str = ft_memset(str, c, i);
	str[i] = 0;
	*s = ft_strjoin_freeboth(*s, str);
	if (!*s)
		return (1);
	return (0);
}

int	ft_padleft_char(int i, char c, char **s)
{
	char	*str;

	str = malloc(i + 1);
	if (!str)
		return (1);
	str[i] = 0;
	str = ft_memset(str, c, i);
	str[i] = 0;
	str[i - 1] = *s[0];
	free(*s);
	*s = str;
	return (0);
}

int	ft_padright_char(int i, char c, char **s)
{
	char	*str;

	str = malloc(i + 1);
	if (!str)
		return (1);
	str[i] = 0;
	str = ft_memset(str, c, i);
	str[i] = 0;
	str[0] = *s[0];
	free(*s);
	*s = str;
	return (0);
}
