/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:23:40 by okraus            #+#    #+#             */
/*   Updated: 2023/07/28 19:52:21 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	j = ft_strlen(s1);
	i = ft_strlen(s2);
	s3 = (char *)malloc((i + j + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		s3[i + j] = s2[i];
		i++;
	}
	s3[i + j] = 0;
	return (s3);
}
