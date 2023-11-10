/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:12:03 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:13:37 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	while (s[i] != 0)
		i++;
	len = i;
	i = 0;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (dest);
	else
	{
		while (i < len)
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = 0;
	}
	return (dest);
}
