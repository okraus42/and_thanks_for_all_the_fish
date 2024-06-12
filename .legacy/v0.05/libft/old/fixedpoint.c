/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixedpoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:29:03 by okraus            #+#    #+#             */
/*   Updated: 2023/11/12 17:18:55 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/libft.h"

int	main(int ac, char *av[])
{
	double	f;
	t_fix64	fix;

	if (ac != 2)
		return (5);
	f = atof(av[1]);
	printf("Float is: %20.3f\n", f);
	fix = ft_ftofix(f, 16);
	ft_printf("Fix is %23.3LP\n", fix);
	ft_printf("Next fix is %18.3LP\nPrevious fix is %14.3LP\n", fix + 1, fix - 1);
	return (0);
}
