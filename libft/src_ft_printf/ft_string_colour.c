/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_colour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:55:41 by okraus            #+#    #+#             */
/*   Updated: 2023/06/17 15:51:28 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_putcolour_fd(int fd, t_output *t)
{
	int		i;

	i = 0;
	if (t->padsize < 10)
		i = ft_print_colour_fd_0(fd, t);
	else if (t->padsize < 20)
		i = ft_print_colour_fd_1(fd, t);
	else if (t->padsize < 30)
		i = ft_print_colour_fd_2(fd, t);
	else if (t->padsize < 40)
		i = ft_print_colour_fd_3(fd, t);
	else if (t->padsize < 50)
		i = ft_print_colour_fd_4(fd, t);
	else if (t->padsize < 60)
		i = ft_print_colour_fd_5(fd, t);
	else if (t->padsize < 70)
		i = ft_print_colour_fd_6(fd, t);
	else if (t->padsize < 80)
		i = ft_print_colour_fd_7(fd, t);
	else if (t->padsize < 90)
		i = ft_print_colour_fd_8(fd, t);
	else if (t->padsize < 100)
		i = ft_print_colour_fd_9(fd, t);
	return (i);
}
