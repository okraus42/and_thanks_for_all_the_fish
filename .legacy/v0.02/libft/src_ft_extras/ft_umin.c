/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:42:07 by okraus            #+#    #+#             */
/*   Updated: 2023/06/11 11:59:37 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

unsigned int	ft_umin(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
