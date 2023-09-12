/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:14:02 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:12:29 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_padchar(char *s, int len, t_output *t)
{
	while ((int)ft_strlen(s) < t->padsize - len)
	{
		s = ft_strjoin_freeright(" ", s);
	}
	return (s);
}

char	*ft_padint(char *s, t_output *t)
{
	if (t->padsize && !t->zero)
	{
		while ((int)ft_strlen(s) < t->padsize && !t->dash)
		{
			s = ft_strjoin_freeright(" ", s);
		}
		while ((int)ft_strlen(s) < t->padsize && t->dash)
		{
			s = ft_strjoin_freeleft(s, " ");
		}
	}
	return (s);
}

char	*ft_precint(char *s, t_output *t)
{
	int	sign;

	sign = 0;
	if (s[0] == '-' && ((int)ft_strlen(s) <= t->precision
			|| (t->zero && (int)ft_strlen(s) <= t->padsize)))
	{
		sign = -1;
		s[0] = '0';
	}
	while ((int)ft_strlen(s) < t->precision)
	{
		s = ft_strjoin_freeright("0", s);
	}
	while (!t->precision && t->zero && (int)ft_strlen(s) < t->padsize)
	{
		s = ft_strjoin_freeright("0", s);
	}
	if (sign == -1)
	{
		if (t->zero)
			s[0] = '-';
		else
			s = ft_strjoin_freeright("-", s);
	}
	return (s);
}
