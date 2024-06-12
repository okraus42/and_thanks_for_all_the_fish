/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:27:59 by okraus            #+#    #+#             */
/*   Updated: 2023/08/15 16:10:28 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *))
{
	if (dlst)
	{
		(*del)(dlst->content);
		free(dlst);
	}
}

void	ft_dlstdelone2(t_dlist *dlst)
{
	if (dlst)
	{
		free(dlst);
	}
}
