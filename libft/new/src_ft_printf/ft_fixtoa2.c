/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixtoa2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:40:48 by okraus            #+#    #+#             */
/*   Updated: 2023/11/18 16:43:26 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static void	ft_fixwhole(int *i, int *j, char *str, char *whole)
{
	while (whole[*j])
	{
		str[*i + *j] = whole[*j];
		++(*j);
	}
	str[*i + *j] = '.';
	*i = *i + *j + 1;
	*j = 0;
}

static void	ft_fixdecimal(int *i, int *j, char *str, char *decimal)
{
	*i = *i + *j;
	*j = 0;
	while (decimal[*j])
	{
		str[*i + *j] = decimal[*j];
		++(*j);
	}
}

char	*ft_fixstr(long long n, int declen, char *whole, char *decimal)
{
	int		i;
	int		j;
	char	*str;
	int		sign;

	sign = 0;
	if (n < 0)
		++sign;
	str = ft_calloc(ft_strlen(whole) + declen + sign + 2, 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (sign)
		str[i++] = '-';
	ft_fixwhole(&i, &j, str, whole);
	while (ft_strlen(decimal) + j < (unsigned long)declen)
	{
		str[i + j] = '0';
		++j;
	}
	ft_fixdecimal(&i, &j, str, decimal);
	return (str);
}
