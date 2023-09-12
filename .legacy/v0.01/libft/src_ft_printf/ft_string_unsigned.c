/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:02:50 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:12:46 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_unslen(unsigned int u)
{
	int	i;

	i = 0;
	if (u <= 0)
		i++;
	while (u)
	{
		u /= 10;
		i++;
	}
	return (i);
}

char	*ft_string_unsigned(unsigned int u)
{
	char			*str;
	int				i;

	i = ft_unslen(u) - 1;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i + 1] = 0;
	if (u == 0)
		str[i] = '0';
	while (u != 0)
	{
		str[i] = "0123456789"[u % 10];
		u = u / 10;
		i--;
	}
	return (str);
}

int	ft_print_unsigned_fd(unsigned int u, int fd, t_output *t)
{
	char	*s;
	int		i;

	s = ft_string_unsigned(u);
	i = 0;
	if (t->precision || (t->padsize && t->zero && !t->precision))
	{
		s = ft_precint(s, t);
	}
	if (t->padsize)
		s = ft_padint(s, t);
	while (s[i])
	{
		i += write(fd, &s[i], 1);
	}
	free(s);
	return (i);
}

int	ft_putunsigned_fd(unsigned int u, int fd, t_output *t)
{
	int		i;

	i = 0;
	if (!u && t->period && !t->precision && t->padsize)
	{
		while (i < t->padsize)
			i += write(fd, " ", 1);
		return (i);
	}
	if (!u && t->period && !t->precision)
		return (0);
	i = ft_print_unsigned_fd(u, fd, t);
	return (i);
}
