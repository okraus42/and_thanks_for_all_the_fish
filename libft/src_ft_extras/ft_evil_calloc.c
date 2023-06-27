/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evil_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:20:43 by okraus            #+#    #+#             */
/*   Updated: 2023/03/15 11:45:06 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_evil_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	i;

	p = ft_calloc(nmemb, size + 64);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * (size + 64))
	{
		if (i < 32 || i > nmemb * (size + 32))
			p[i] = 0xFF;
		else
			p[i] = 1;
		i++;
	}
	p = &p[32];
	return ((void *)p);
}

void	*ft_evil_calloc_plus(size_t nmemb, size_t size, size_t padding)
{
	char	*p;
	size_t	i;

	p = ft_calloc(nmemb, size + (padding * 2));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * (size + (padding * 2)))
	{
		if (i < padding || i > nmemb * (size + padding))
			p[i] = 0xFF;
		else
			p[i] = 1;
		i++;
	}
	p = &p[padding];
	return ((void *)p);
}
