/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uabsdif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:42:14 by okraus            #+#    #+#             */
/*   Updated: 2023/06/11 11:59:35 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

unsigned int	ft_uabsdif(unsigned int a, unsigned int b)
{
	if (a < b)
		return (b - a);
	else
		return (a - b);
}
