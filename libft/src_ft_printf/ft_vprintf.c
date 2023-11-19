/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:34:36 by okraus            #+#    #+#             */
/*   Updated: 2023/10/15 13:37:31 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_vprintf(const char *s, va_list arg)
{
	int		value;
	char	*str;
	int		len;

	len = 0;
	str = ft_get_print_string(arg, s, &len);
	if (str)
	{
		value = write(1, str, len);
		free(str);
	}
	else
		value = (-1);
	return (value);
}

// int	ft_fprintf(FILE *restrict stream, const char *s, va_list arg);

int	ft_vdprintf(int fd, const char *s, va_list arg)
{
	int		value;
	char	*str;
	int		len;

	len = 0;
	str = ft_get_print_string(arg, s, &len);
	if (str)
	{
		value = write(fd, str, len);
		free(str);
	}
	else
		value = (-1);
	return (value);
}

int	ft_vsprintf(char *str, const char *s, va_list arg)
{
	int		value;
	char	*temp;
	int		len;

	len = 0;
	temp = ft_get_print_string(arg, s, &len);
	if (temp)
	{
		value = ft_snpf_strncpy(str, temp, len, len);
		free(temp);
	}
	else
		value = (-1);
	return (value);
}

int	ft_vsnprintf(char *str, size_t size, const char *s, va_list arg)
{
	int		value;
	char	*temp;
	int		len;

	len = 0;
	temp = ft_get_print_string(arg, s, &len);
	if (temp)
	{
		value = ft_snpf_strncpy(str, temp, size, len);
		free(temp);
	}
	else
		value = (-1);
	return (value);
}
