/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:59:58 by okraus            #+#    #+#             */
/*   Updated: 2023/10/15 13:38:18 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_printf(const char *s, ...)
{
	int		value;
	char	*str;
	int		len;
	va_list	arg;

	len = 0;
	va_start(arg, s);
	str = ft_get_print_string(arg, s, &len);
	va_end(arg);
	if (str)
	{
		value = write(1, str, len);
		free(str);
	}
	else
		value = (-1);
	return (value);
}

// int	ft_fprintf(FILE *restrict stream, const char *s, ...);

int	ft_dprintf(int fd, const char *s, ...)
{
	int		value;
	char	*str;
	int		len;
	va_list	arg;

	len = 0;
	va_start(arg, s);
	str = ft_get_print_string(arg, s, &len);
	va_end(arg);
	if (str)
	{
		value = write(fd, str, len);
		free(str);
	}
	else
		value = (-1);
	return (value);
}

int	ft_sprintf(char *str, const char *s, ...)
{
	int		value;
	char	*temp;
	int		len;
	va_list	arg;

	len = 0;
	va_start(arg, s);
	temp = ft_get_print_string(arg, s, &len);
	va_end(arg);
	if (temp)
	{
		value = ft_snpf_strncpy(str, temp, len, len);
		free(temp);
	}
	else
		value = (-1);
	return (value);
}

int	ft_snprintf(char *str, size_t size, const char *s, ...)
{
	int		value;
	char	*temp;
	int		len;
	va_list	arg;

	len = 0;
	va_start(arg, s);
	temp = ft_get_print_string(arg, s, &len);
	va_end(arg);
	if (temp)
	{
		value = ft_snpf_strncpy(str, temp, size, len);
		free(temp);
	}
	else
		value = (-1);
	return (value);
}
