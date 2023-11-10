/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_binocthex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:02:50 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:12:36 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

/*
t->string = NULL;
	t->len = 0;
	t->precision = 0;	// base
	t->padsize = 0;		// how many bytes
	t->dash = 0;		// read memory backwards
	t->zero = 0;		// ignored
	t->period = 0;		// base
	t->hash = 0;		// print "0P"
	t->space = 0;		// add space between bytes
	t->plus = 0;		// ignore
	t->type = 0;		// ignored for now, capitalization?
	t->base = 0;		// ignored, used precision set base based on type
*/

static int	ft_binocthexlen(t_output *t)
{
	int	i;
	int	c;

	i = 0;
	c = 0xFF;
	while (c)
	{
		c /= t->precision;
		i++;
	}
	return (i);
}

char	*ft_string_binocthex(unsigned char b, t_output *t)
{
	char			*str;
	int				i;

	i = ft_binocthexlen(t) - 1;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i + 1] = 0;
	str[0] = '0';
	while (b != 0)
	{
		str[i] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[b % t->precision];
		b = b / t->precision;
		i--;
	}
	while (i > 0)
	{
		str[i] = '0';
		i--;
	}
	return (str);
}

int	ft_print_binocthex_fd(unsigned char b, int fd, t_output *t)
{
	char	*s;
	int		i;

	s = ft_string_binocthex(b, t);
	i = 0;
	while (s[i])
		i += write(fd, &s[i], 1);
	free(s);
	return (i);
}

/*
t->string = NULL;
	t->len = 0;
	t->precision = 0;	// base
	t->padsize = 0;		// how many bytes
	t->dash = 0;		// read memory backwards
	t->zero = 0;		// ignored
	t->period = 0;		// base
	t->hash = 0;		// print "0P"
	t->space = 0;		// add space between bytes
	t->plus = 0;		// ignore
	t->type = 0;		// ignored for now, capitalization?
	t->base = 0;		// ignored, used precision set base based on type
*/

int	ft_putbinocthex_fd(void *b, int fd, t_output *t)
{
	int				i;
	int				j;
	unsigned char	c;

	i = 0;
	j = 0;
	if (t->hash)
		i += write(fd, "0P", 2);
	while (j < t->padsize && !t->dash)
	{
		c = *(unsigned char *)(b + j);
		i += ft_print_binocthex_fd(c, fd, t);
		j++;
		if (t->space && j < t->padsize)
			write(fd, " ", 1);
	}
	while (j < t->padsize && t->dash)
	{
		c = *(unsigned char *)(b - j);
		i += ft_print_binocthex_fd(c, fd, t);
		j++;
		if (t->space && j < t->padsize)
			write(fd, " ", 1);
	}
	return (i);
}
