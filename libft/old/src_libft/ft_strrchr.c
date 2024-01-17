/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:35:03 by okraus            #+#    #+#             */
/*   Updated: 2023/08/15 16:08:55 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*a;

	i = 0;
	a = NULL;
	while (s[i])
	{
		if (s[i] == (c % 256))
			a = (char *)&s[i];
		i++;
	}
	if (s[i] == (c % 256))
		a = (char *)&s[i];
	return (a);
}
