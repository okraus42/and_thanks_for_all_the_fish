/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colour_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:48:30 by okraus            #+#    #+#             */
/*   Updated: 2023/06/17 15:57:50 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_print_colour_fd_0(int fd, t_output *t)
{
	int	i;

	i = 0;
	if (t->padsize == 1)
		i += write(fd, "\033[31m", 5);
	else if (t->padsize == 2)
		i += write(fd, "\033[32m", 5);
	else if (t->padsize == 3)
		i += write(fd, "\033[33m", 5);
	else if (t->padsize == 4)
		i += write(fd, "\033[34m", 5);
	else if (t->padsize == 5)
		i += write(fd, "\033[35m", 5);
	else if (t->padsize == 6)
		i += write(fd, "\033[36m", 5);
	else if (t->padsize == 7)
		i += write(fd, "\033[37m", 5);
	else if (t->padsize == 8)
		i += write(fd, "\033[30m", 5);
	else if (t->padsize == 9)
		i += write(fd, "\033[1;5;97;41m", 12);
	else
		i += write(fd, "\033[0m", 4);
	return (i);
}

int	ft_print_colour_fd_1(int fd, t_output *t)
{
	int	i;

	i = 0;
	if (t->padsize == 11)
		i += write(fd, "\033[91m", 5);
	else if (t->padsize == 12)
		i += write(fd, "\033[92m", 5);
	else if (t->padsize == 13)
		i += write(fd, "\033[93m", 5);
	else if (t->padsize == 14)
		i += write(fd, "\033[94m", 5);
	else if (t->padsize == 15)
		i += write(fd, "\033[95m", 5);
	else if (t->padsize == 16)
		i += write(fd, "\033[96m", 5);
	else if (t->padsize == 17)
		i += write(fd, "\033[97m", 5);
	else if (t->padsize == 18)
		i += write(fd, "\033[90m", 5);
	else if (t->padsize == 19)
		i += write(fd, "\033[1;5;97;41m", 12);
	else
		i += write(fd, "\033[0m", 4);
	return (i);
}

int	ft_print_colour_fd_2(int fd, t_output *t)
{
	int	i;

	i = 0;
	if (t->padsize == 21)
		i += write(fd, "\033[1;31m", 7);
	else if (t->padsize == 22)
		i += write(fd, "\033[1;32m", 7);
	else if (t->padsize == 23)
		i += write(fd, "\033[1;33m", 7);
	else if (t->padsize == 24)
		i += write(fd, "\033[1;34m", 7);
	else if (t->padsize == 25)
		i += write(fd, "\033[1;35m", 7);
	else if (t->padsize == 26)
		i += write(fd, "\033[1;36m", 7);
	else if (t->padsize == 27)
		i += write(fd, "\033[1;37m", 7);
	else if (t->padsize == 28)
		i += write(fd, "\033[1;30m", 7);
	else if (t->padsize == 29)
		i += write(fd, "\033[1;5;97;41m", 12);
	else
		i += write(fd, "\033[0m", 4);
	return (i);
}

int	ft_print_colour_fd_3(int fd, t_output *t)
{
	int	i;

	i = 0;
	if (t->padsize == 31)
		i += write(fd, "\033[1;91m", 7);
	else if (t->padsize == 32)
		i += write(fd, "\033[1;92m", 7);
	else if (t->padsize == 33)
		i += write(fd, "\033[1;93m", 7);
	else if (t->padsize == 34)
		i += write(fd, "\033[1;94m", 7);
	else if (t->padsize == 35)
		i += write(fd, "\033[1;95m", 7);
	else if (t->padsize == 36)
		i += write(fd, "\033[1;96m", 7);
	else if (t->padsize == 37)
		i += write(fd, "\033[1;97m", 7);
	else if (t->padsize == 38)
		i += write(fd, "\033[1;90m", 7);
	else if (t->padsize == 39)
		i += write(fd, "\033[1;5;97;41m", 12);
	else
		i += write(fd, "\033[0m", 4);
	return (i);
}

int	ft_print_colour_fd_4(int fd, t_output *t)
{
	int	i;

	i = 0;
	if (t->padsize == 41)
		i += write(fd, "\033[97;41m", 8);
	else if (t->padsize == 42)
		i += write(fd, "\033[97;42m", 8);
	else if (t->padsize == 43)
		i += write(fd, "\033[97;43m", 8);
	else if (t->padsize == 44)
		i += write(fd, "\033[97;44m", 8);
	else if (t->padsize == 45)
		i += write(fd, "\033[97;45m", 8);
	else if (t->padsize == 46)
		i += write(fd, "\033[97;46m", 8);
	else if (t->padsize == 47)
		i += write(fd, "\033[30;47m", 8);
	else if (t->padsize == 48)
		i += write(fd, "\033[97;40m", 8);
	else if (t->padsize == 49)
		i += write(fd, "\033[1;5;97;41m", 12);
	else
		i += write(fd, "\033[0m", 4);
	return (i);
}
