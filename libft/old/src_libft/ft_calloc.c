/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:48:51 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:12:57 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_safemultiply_check(size_t a, size_t b, size_t max)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (max > 0)
	{
		max = max / 2;
		k++;
	}
	while (a > 0)
	{
		a = a / 2;
		i++;
	}
	while (b > 0)
	{
		b = b / 2;
		j++;
	}
	if (i + j > k)
		return (0);
	return (1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	i;
	size_t	t;

	t = -1;
	if (!ft_safemultiply_check(nmemb, size, t))
	{
		return (NULL);
	}
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
