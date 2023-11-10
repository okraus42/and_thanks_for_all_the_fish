/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:54:23 by okraus            #+#    #+#             */
/*   Updated: 2023/11/10 10:17:34 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/and_thanks_for_all_the_fish.h"

time_t	ft_get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_update_gametime_in_ms(t_max *max)
{
	time_t	mtimenow;

	mtimenow = ft_get_time_in_ms();
	max->key->mtime += mtimenow - max->key->mtimenow;
	max->key->mtimenow = mtimenow;
}