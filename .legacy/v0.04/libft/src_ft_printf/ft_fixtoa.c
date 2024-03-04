/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:40:45 by okraus            #+#    #+#             */
/*   Updated: 2023/11/20 16:00:13 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_get_declen(unsigned int fixbits)
{
	unsigned int		i;
	int					declen;
	long long			j;
	unsigned long long	fives;
	char				*decimal;

	i = 0;
	j = 1;
	fives = 1;
	while (++i <= fixbits)
	{
		j *= 2;
		fives *= 5;
	}
	--j;
	decimal = ft_ultoa_base(j * fives, "0123456789", 10);
	if (!decimal)
		return (-1);
	declen = ft_strlen(decimal);
	free(decimal);
	return (declen);
}

static void	ft_get_dw(long long n, unsigned int fb, char **dec, char **wh)
{
	long long			w[2];
	unsigned long long	d;
	unsigned int		i;
	unsigned long long	fives;

	w[1] = 1;
	fives = 1;
	i = 0;
	while (++i <= fb)
	{
		w[1] *= 2;
		fives *= 5;
	}
	--w[1];
	if (n >= 0)
		w[0] = n >> fb;
	else
		w[0] = (-n) >> fb;
	if (n >= 0)
		d = n & w[1];
	else
		d = (-n) & w[1];
	d *= fives;
	*wh = ft_litoa(w[0]);
	*dec = ft_ultoa_base(d, "0123456789", 10);
}

char	*ft_fixtoa(long long n, unsigned int fixbits)
{
	char				*whole;
	char				*decimal;
	char				*str;
	int					declen;

	if (!fixbits || fixbits > 16)
		fixbits = 16;
	declen = ft_get_declen(fixbits);
	if (declen < 0)
		return (NULL);
	whole = NULL;
	decimal = NULL;
	ft_get_dw(n, fixbits, &decimal, &whole);
	if (!whole && !decimal)
		return (NULL);
	else if (!whole)
		return (free(decimal), NULL);
	else if (!decimal)
		return (free(whole), NULL);
	str = ft_fixstr(n, declen, whole, decimal);
	free (whole);
	free (decimal);
	return (str);
}
