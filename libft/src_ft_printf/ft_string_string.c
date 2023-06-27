/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:02:55 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:12:44 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_print_char_fd(char c, int fd, t_output *t)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc(sizeof(char));
	s[0] = 0;
	if (t->dash)
		i += write(fd, &c, 1);
	if (t->padsize > 1)
		s = ft_padchar(s, 1, t);
	while (s[i])
	{
		i += write(fd, &s[i], 1);
	}
	if (t->dash && s[0])
		i += write(fd, &s[0], 1);
	if (!t->dash)
		i += write(fd, &c, 1);
	free(s);
	return (i);
}

int	ft_pf_putchar_fd(char c, int fd, t_output *t)
{
	int	i;

	i = 0;
	i = ft_print_char_fd(c, fd, t);
	return (i);
}

int	ft_print_string_fd(char *s, int fd, t_output *t)
{
	int	i;

	i = 0;
	if (s == NULL && (!t->period || t->precision > 5))
	{
		write(fd, "(null)", 6);
		return (6);
	}
	else if (s == NULL)
		return (0);
	while (s[i] && (!t->period || i < t->precision))
		i += write(fd, &s[i], 1);
	return (i);
}

int	ft_putstring_fd(char *s, int fd, t_output *t)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 6;
	if (s)
		len = ft_strlen(s);
	if (s && t->period && len > t->precision)
		len = t->precision;
	str = malloc(sizeof(char));
	str[0] = 0;
	if (t->dash)
		i += ft_print_string_fd(s, fd, t);
	if (t->padsize > len)
		str = ft_padchar(str, len, t);
	len = 0;
	while (str[len])
		len += write(fd, &str[len], 1);
	if (!t->dash)
		i += ft_print_string_fd(s, fd, t);
	free(str);
	return (i + len);
}
