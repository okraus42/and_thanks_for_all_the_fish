/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:42:00 by okraus            #+#    #+#             */
/*   Updated: 2023/06/11 14:13:57 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

int	ft_base_pos(const char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != c)
	{
		i++;
	}
	return (i);
}

int	ft_strchar(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

unsigned int	ft_atoi_base(const char *base, char *str)
{
	int				baselen;
	int				i;
	unsigned int	num;

	num = 0;
	i = 0;
	baselen = ft_strlen2(base);
	while (str[i] && ft_strchar(base, str[i]))
	{
		num = num * baselen + ft_base_pos(base, str[i]);
		i++;
	}
	return (num);
}
