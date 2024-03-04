/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftofix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:48:21 by okraus            #+#    #+#             */
/*   Updated: 2023/11/20 16:11:21 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

t_fix64	ft_ftofix(double f, unsigned int bits)
{
	t_fix64			fix;
	int				power;
	unsigned int	i;

	power = 2;
	i = 1;
	if (bits < 1 || bits > 16)
		bits = 16;
	while (i++ < bits)
	{
		power *= 2;
	}
	if (f >= 0)
		fix = (long long)(((f) * power) + 0.5);
	else
		fix = (long long)(((f) * power) - 0.5);
	return (fix);
}
