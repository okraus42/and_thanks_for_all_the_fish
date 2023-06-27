/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colour_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:48:47 by okraus            #+#    #+#             */
/*   Updated: 2023/06/17 15:49:04 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_print_colour_fd_5(int fd, t_output *t)
{
	int	i;

	i = 0;
	if (t->padsize == 51)
		i += write(fd, "\033[97;101m", 9);
	else if (t->padsize == 52)
		i += write(fd, "\033[30;102m", 9);
	else if (t->padsize == 53)
		i += write(fd, "\033[30;103m", 9);
	else if (t->padsize == 54)
		i += write(fd, "\033[97;104m", 9);
	else if (t->padsize == 55)
		i += write(fd, "\033[97;105m", 9);
	else if (t->padsize == 56)
		i += write(fd, "\033[97;106m", 9);
	else if (t->padsize == 57)
		i += write(fd, "\033[30;107m", 9);
	else if (t->padsize == 58)
		i += write(fd, "\033[97;100m", 9);
	else if (t->padsize == 59)
		i += write(fd, "\033[1;5;97;41m", 12);
	else
		i += write(fd, "\033[0m", 4);
	return (i);
}

int	ft_print_colour_fd_6(int fd, t_output *t)
{
	int	i;

	i = 0;
	if (t->padsize == 61)
		i += write(fd, "\033[1;97;41m", 10);
	else if (t->padsize == 62)
		i += write(fd, "\033[1;97;42m", 10);
	else if (t->padsize == 63)
		i += write(fd, "\033[1;97;43m", 10);
	else if (t->padsize == 64)
		i += write(fd, "\033[1;97;44m", 10);
	else if (t->padsize == 65)
		i += write(fd, "\033[1;97;45m", 10);
	else if (t->padsize == 66)
		i += write(fd, "\033[1;97;46m", 10);
	else if (t->padsize == 67)
		i += write(fd, "\033[1;30;47m", 10);
	else if (t->padsize == 68)
		i += write(fd, "\033[1;97;40m", 10);
	else if (t->padsize == 69)
		i += write(fd, "\033[1;5;97;41m", 12);
	else
		i += write(fd, "\033[0m", 4);
	return (i);
}

int	ft_print_colour_fd_7(int fd, t_output *t)
{
	int	i;

	i = 0;
	if (t->padsize == 71)
		i += write(fd, "\033[1;97;101m", 11);
	else if (t->padsize == 72)
		i += write(fd, "\033[1;30;102m", 11);
	else if (t->padsize == 73)
		i += write(fd, "\033[1;30;103m", 11);
	else if (t->padsize == 74)
		i += write(fd, "\033[1;97;104m", 11);
	else if (t->padsize == 75)
		i += write(fd, "\033[1;97;105m", 11);
	else if (t->padsize == 76)
		i += write(fd, "\033[1;97;106m", 11);
	else if (t->padsize == 77)
		i += write(fd, "\033[1;30;107m", 11);
	else if (t->padsize == 78)
		i += write(fd, "\033[1;97;100m", 11);
	else if (t->padsize == 79)
		i += write(fd, "\033[1;5;97;41m", 12);
	else
		i += write(fd, "\033[0m", 4);
	return (i);
}

int	ft_print_colour_fd_8(int fd, t_output *t)
{
	int	i;

	i = 0;
	if (t->padsize == 81)
		i += write(fd, "\033[1;5;31m", 9);
	else if (t->padsize == 82)
		i += write(fd, "\033[1;5;32m", 9);
	else if (t->padsize == 83)
		i += write(fd, "\033[1;5;33m", 9);
	else if (t->padsize == 84)
		i += write(fd, "\033[1;5;34m", 9);
	else if (t->padsize == 85)
		i += write(fd, "\033[1;5;35m", 9);
	else if (t->padsize == 86)
		i += write(fd, "\033[1;5;36m", 9);
	else if (t->padsize == 87)
		i += write(fd, "\033[1;5;37m", 9);
	else if (t->padsize == 88)
		i += write(fd, "\033[1;5;30m", 9);
	else if (t->padsize == 89)
		i += write(fd, "\033[1;5;97;41m", 12);
	else
		i += write(fd, "\033[0m", 4);
	return (i);
}

int	ft_print_colour_fd_9(int fd, t_output *t)
{
	int	i;

	i = 0;
	if (t->padsize == 91)
		i += write(fd, "\033[1;5;97;41m", 12);
	else if (t->padsize == 92)
		i += write(fd, "\033[1;5;97;42m", 12);
	else if (t->padsize == 93)
		i += write(fd, "\033[1;5;97;43m", 12);
	else if (t->padsize == 94)
		i += write(fd, "\033[1;5;97;44m", 12);
	else if (t->padsize == 95)
		i += write(fd, "\033[1;5;97;45m", 12);
	else if (t->padsize == 96)
		i += write(fd, "\033[1;5;97;46m", 12);
	else if (t->padsize == 97)
		i += write(fd, "\033[1;5;30;47m", 12);
	else if (t->padsize == 98)
		i += write(fd, "\033[1;5;97;40m", 12);
	else if (t->padsize == 99)
		i += write(fd, "\033[1;5;97;41m", 12);
	else
		i += write(fd, "\033[0m", 4);
	return (i);
}
