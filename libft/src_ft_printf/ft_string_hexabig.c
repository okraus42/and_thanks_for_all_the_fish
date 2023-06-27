/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_hexabig.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:02:50 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:12:39 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_hexlen(unsigned int h)
{
	int	i;

	i = 0;
	if (h <= 0)
		i++;
	while (h != 0)
	{
		h = h / 16;
		i++;
	}
	return (i);
}

char	*ft_string_hexabig(unsigned int h)
{
	char			*str;
	int				i;

	i = ft_hexlen(h) - 1;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i + 1] = 0;
	if (h == 0)
		str[i] = '0';
	while (h != 0)
	{
		str[i] = "0123456789ABCDEF"[h % 16];
		h = h / 16;
		i--;
	}
	return (str);
}

int	ft_print_hexabig_fd(unsigned int h, int fd, t_output *t)
{
	char	*s;
	int		i;

	s = ft_string_hexabig(h);
	i = 0;
	if (t->hash && h)
		s = ft_strjoin_freeright("0X", s);
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

int	ft_puthexabig_fd(unsigned int h, int fd, t_output *t)
{
	int		i;

	i = 0;
	if (!h && t->period && !t->precision && t->padsize)
	{
		while (i < t->padsize)
			i += write(fd, " ", 1);
		return (i);
	}
	if (!h && t->period && !t->precision)
		return (0);
	i = ft_print_hexabig_fd(h, fd, t);
	return (i);
}
