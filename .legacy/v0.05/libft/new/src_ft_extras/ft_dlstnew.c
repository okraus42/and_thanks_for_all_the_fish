/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:25:05 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:12:17 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*dlst;

	dlst = malloc(sizeof(t_dlist));
	if (dlst == NULL)
		return (NULL);
	dlst->content = content;
	dlst->prev = NULL;
	dlst->next = NULL;
	return (dlst);
}
