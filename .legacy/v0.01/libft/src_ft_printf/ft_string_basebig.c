/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_basebig.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:02:50 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:12:35 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_baselen(unsigned int b, t_output *t)
{
	int	i;

	i = 0;
	if (b <= 0)
		i++;
	while (b != 0)
	{
		b = b / t->precision;
		i++;
	}
	return (i);
}

char	*ft_string_basebig(unsigned int b, t_output *t)
{
	char			*str;
	int				i;

	i = ft_baselen(b, t) - 1;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i + 1] = 0;
	if (b == 0)
		str[i] = '0';
	while (b != 0)
	{
		str[i] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[b % t->precision];
		b = b / t->precision;
		i--;
	}
	return (str);
}

int	ft_print_basebig_fd(unsigned int b, int fd, t_output *t)
{
	char	*s;
	int		i;

	s = ft_string_basebig(b, t);
	i = 0;
	if (t->padsize && t->plus)
		while ((int)ft_strlen(s) < t->padsize)
			s = ft_strjoin_freeright("0", s);
	if (t->hash && b)
		s = ft_strjoin_freeright("#B#", s);
	if (t->padsize && !t->plus)
	{
		while ((int)ft_strlen(s) < t->padsize && !t->dash)
			s = ft_strjoin_freeright(" ", s);
		while ((int)ft_strlen(s) < t->padsize && t->dash)
			s = ft_strjoin_freeleft(s, " ");
	}
	while (s[i])
		i += write(fd, &s[i], 1);
	free(s);
	return (i);
}

int	ft_putbasebig_fd(unsigned int b, int fd, t_output *t)
{
	int		i;

	i = 0;
	if (t->precision < 2 || t->precision > 36)
		return (0);
	i = ft_print_basebig_fd(b, fd, t);
	return (i);
}
