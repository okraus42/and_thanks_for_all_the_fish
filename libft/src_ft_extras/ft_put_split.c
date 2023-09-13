/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:11:53 by okraus            #+#    #+#             */
/*   Updated: 2023/07/16 12:12:44 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_put_split(char **split)
{
	int	i;

	if (!split)
		ft_printf_fd(2, "split is %s\n", split);
	i = 0;
	while (split[i])
	{
		ft_printf("%s\n", split[i]);
		i++;
	}
}
