/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:02:44 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:13:04 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_numlen(int n)
{
	if (n < -999999999)
		return (11);
	if (n < -99999999 || n > 999999999)
		return (10);
	if (n < -9999999 || n > 99999999)
		return (9);
	if (n < -999999 || n > 9999999)
		return (8);
	if (n < -99999 || n > 999999)
		return (7);
	if (n < -9999 || n > 99999)
		return (6);
	if (n < -999 || n > 9999)
		return (5);
	if (n < -99 || n > 999)
		return (4);
	if (n < -9 || n > 99)
		return (3);
	if (n < 0 || n > 9)
		return (2);
	return (1);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	m;

	i = ft_numlen(n) - 1;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i + 1] = 0;
	if (n == 0)
		str[i] = '0';
	if (n < 0)
	{
		str[0] = '-';
		m = -n;
	}
	else
		m = n;
	while (m != 0)
	{
		str[i] = m % 10 + '0';
		m = m / 10;
		i--;
	}
	return (str);
}
