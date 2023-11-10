/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:02:50 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:12:41 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_intlen(int d)
{
	int	i;

	i = 0;
	if (d <= 0)
		i++;
	while (d)
	{
		d /= 10;
		i++;
	}
	return (i);
}

char	*ft_string_integer(int d)
{
	char			*str;
	int				i;
	unsigned int	m;

	i = ft_intlen(d) - 1;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i + 1] = 0;
	if (d == 0)
		str[i] = '0';
	if (d < 0)
	{
		str[0] = '-';
		m = -d;
	}
	else
		m = d;
	while (m != 0)
	{
		str[i] = "0123456789"[m % 10];
		m = m / 10;
		i--;
	}
	return (str);
}

int	ft_print_integer_fd(int d, int fd, t_output	*t)
{
	char	*s;
	int		i;

	s = ft_string_integer(d);
	i = 0;
	if (t->precision || (t->padsize && t->zero && !t->precision))
	{
		s = ft_precint(s, t);
	}
	if (t->plus && d >= 0)
		s = ft_strjoin_freeright("+", s);
	else if (t->space && d >= 0)
		s = ft_strjoin_freeright(" ", s);
	if (t->padsize)
		s = ft_padint(s, t);
	while (s[i])
	{
		i += write(fd, &s[i], 1);
	}
	free(s);
	return (i);
}

int	ft_putinteger_fd(int d, int fd, t_output *t)
{
	int		i;

	i = 0;
	if (!d && t->period && !t->precision && t->padsize)
	{
		while (i < t->padsize)
			i += write(fd, " ", 1);
		return (i);
	}
	if (!d && t->period && !t->precision)
		return (0);
	i = ft_print_integer_fd(d, fd, t);
	return (i);
}
