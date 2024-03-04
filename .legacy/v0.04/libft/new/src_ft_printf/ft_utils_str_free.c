/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_str_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:29:03 by okraus            #+#    #+#             */
/*   Updated: 2023/10/15 13:42:53 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_snpf_strncpy(char *str, char *temp, size_t size, int len)
{
	int	i;
	int	min;

	i = 0;
	if (size > INT_MAX)
		return (-1);
	min = (int)size;
	if (len < min)
		min = len;
	while (i < min)
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	return (i);
}

char	*ft_string_copy_n(char const *str, int n)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(str);
	if (n < len)
		len = n;
	if (!str)
		return (NULL);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin_freeright(char const *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	j = ft_strlen(s1);
	i = ft_strlen(s2);
	s3 = (char *)malloc((i + j + 1) * sizeof(char));
	if (s3 == NULL)
		return (free(s2), NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s3[i + j] = s2[i];
		i++;
	}
	s3[i + j] = 0;
	return (free(s2), s3);
}

char	*ft_strjoin_freeleft(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	j = ft_strlen(s1);
	i = ft_strlen(s2);
	s3 = (char *)malloc((i + j + 1) * sizeof(char));
	if (s3 == NULL)
		return (free(s1), NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s3[i + j] = s2[i];
		i++;
	}
	s3[i + j] = 0;
	return (free(s1), s3);
}

char	*ft_strjoin_freeboth(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	j = ft_strlen(s1);
	i = ft_strlen(s2);
	s3 = malloc((i + j + 1) * sizeof(char));
	if (s3 == NULL)
		return (free(s1), free(s2), NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s3[i + j] = s2[i];
		i++;
	}
	s3[i + j] = 0;
	return (free(s1), free(s2), s3);
}
