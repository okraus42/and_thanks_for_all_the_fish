/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmoveone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:34:16 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:12:15 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_dlstmovein(t_dlist **dlst_dst, t_dlist *dlst_src)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;
	t_dlist	*tmp3;

	tmp = *dlst_dst;
	tmp3 = dlst_src;
	if (tmp)
	{
		tmp3->next = tmp;
		tmp3->prev = tmp;
		tmp2 = tmp->prev;
		tmp->prev = tmp3;
		if (tmp2)
		{
			tmp2->next = tmp3;
			tmp3->prev = tmp2;
		}
		else
		{
			tmp->next = tmp3;
			tmp->prev = tmp3;
		}
	}
}

void	ft_dlstmoveout(t_dlist **dlst_src)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;

	if (*dlst_src)
	{
		tmp = *dlst_src;
		if (tmp->next)
		{
			tmp2 = tmp->next;
			if (tmp->next != tmp->prev)
			{
				tmp = tmp->prev;
				tmp2->prev = tmp;
				tmp->next = tmp2;
			}
			else
			{
				tmp2->next = NULL;
				tmp2->prev = NULL;
			}
		}
	}
}

void	ft_dlstmoveone(t_dlist **dlst_dst, t_dlist **dlst_src)
{
	t_dlist	*tmps;

	tmps = *dlst_src;
	ft_dlstmoveout(dlst_src);
	ft_dlstmovein(dlst_dst, tmps);
	if (!*dlst_dst)
	{
		tmps->next = NULL;
		tmps->prev = NULL;
	}
	*dlst_dst = tmps;
}
