/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:51:51 by okraus            #+#    #+#             */
/*   Updated: 2023/10/14 14:33:33 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_process_prcuns(t_pf_info *data)
{
	if (data->type_flag & LOWERCASE_O && ft_process_prco(data))
		return (1);
	else if (data->type_flag & LOWERCASE_U && ft_process_prcu(data))
		return (1);
	else if (data->type_flag & LOWERCASE_X && ft_process_prcx(data))
		return (1);
	else if (data->type_flag & UPPERCASE_X && ft_process_prcx2(data))
		return (1);
	else if (data->type_flag & UPPERCASE_B && ft_process_prcb2(data))
		return (1);
	if (!data->out)
		return (1);
	return (0);
}

int	ft_process_percent(t_pf_info *data)
{
	int	err;

	err = 1;
	if (data->type_flag & SIGNED_INT)
		err = ft_process_prcint(data);
	if (data->type_flag & CONVERSION_UNSIGNED)
		err = ft_process_prcuns(data);
	if (data->type_flag & PERCENTAGE)
		err = ft_process_prc(data);
	if (data->type_flag & LOWERCASE_S)
		err = ft_process_prcstr(data);
	if (data->type_flag & LOWERCASE_C)
		err = ft_process_prcchr(data);
	if (data->type_flag & UPPERCASE_C)
		err = ft_process_prcclr(data);
	if (data->type_flag & LOWERCASE_P)
		err = ft_process_prcptr(data);
	return (err);
}

int	ft_process_string(t_pf_info *data)
{
	int	len;

	len = 0;
	while (data->orig[len] && data->orig[len] != '%')
		len++;
	data->outlen = len;
	data->out = malloc(len + 1);
	if (!data->out)
		return (1);
	len = 0;
	while (data->orig[len] && data->orig[len] != '%')
	{
		data->out[len] = data->orig[len];
		len++;
	}
	data->out[len] = 0;
	return (0);
}

int	ft_process_list(t_list *lst)
{
	int			err;
	t_pf_info	*data;

	err = 0;
	while (lst)
	{
		data = lst->content;
		if (data->type)
			err = ft_process_percent(data);
		else
			err = ft_process_string(data);
		lst = lst->next;
	}
	return (err);
}
