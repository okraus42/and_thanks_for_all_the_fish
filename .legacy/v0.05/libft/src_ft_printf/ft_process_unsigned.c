/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:39:19 by okraus            #+#    #+#             */
/*   Updated: 2023/10/14 11:07:05 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

//	0x84 PERIOD & MINUS
int	ft_process_prcu(t_pf_info *data)
{
	data->out = ft_ultoa_base(data->value.ull, BASE_CAP, 10);
	if (!data->out)
		return (1);
	if (data->flag & PERIOD || (data->flag & ZERO && !(data->flag & 0x84)))
		if (ft_process_precision(data))
			return (1);
	if (data->value.ull && ft_unsigned_flags(data))
		return (1);
	if (data->field_width > ft_strlen(data->out))
		if (ft_field_width(data))
			return (1);
	data->outlen = ft_strlen(data->out);
	return (0);
}

//	0x84 PERIOD & MINUS
int	ft_process_prco(t_pf_info *data)
{
	data->out = ft_ultoa_base(data->value.ull, BASE_CAP, 8);
	if (!data->out)
		return (1);
	if (data->flag & PERIOD || (data->flag & ZERO && !(data->flag & 0x84)))
		if (ft_process_precision(data))
			return (1);
	if (data->value.ull && ft_unsigned_flags(data))
		return (1);
	if (data->field_width > ft_strlen(data->out))
		if (ft_field_width(data))
			return (1);
	data->outlen = ft_strlen(data->out);
	return (0);
}

//	0x84 PERIOD & MINUS
int	ft_process_prcx(t_pf_info *data)
{
	data->out = ft_ultoa_base(data->value.ull, BASE_SML, 16);
	if (!data->out)
		return (1);
	if (data->flag & PERIOD || (data->flag & ZERO && !(data->flag & 0x84)))
		if (ft_process_precision(data))
			return (1);
	if (data->value.ull && ft_unsigned_flags(data))
		return (1);
	if (data->field_width > ft_strlen(data->out))
		if (ft_field_width(data))
			return (1);
	data->outlen = ft_strlen(data->out);
	return (0);
}

//	0x84 PERIOD & MINUS
int	ft_process_prcx2(t_pf_info *data)
{
	data->out = ft_ultoa_base(data->value.ull, BASE_CAP, 16);
	if (!data->out)
		return (1);
	if (data->flag & PERIOD || (data->flag & ZERO && !(data->flag & 0x84)))
		if (ft_process_precision(data))
			return (1);
	if (data->value.ull && ft_unsigned_flags(data))
		return (1);
	if (data->field_width > ft_strlen(data->out))
		if (ft_field_width(data))
			return (1);
	data->outlen = ft_strlen(data->out);
	return (0);
}

int	ft_process_prcb2(t_pf_info *data)
{
	if (data->baselen < 2 || data->baselen > 36)
		data->baselen = 2;
	data->out = ft_ultoa_base(data->value.ull, BASE_CAP, (int)data->baselen);
	if (!data->out)
		return (1);
	if (data->flag & PERIOD || (data->flag & ZERO && !(data->flag & 0x84)))
		if (ft_process_precision(data))
			return (1);
	if (data->value.ull && ft_unsigned_flags(data))
		return (1);
	if (data->field_width > ft_strlen(data->out))
		if (ft_field_width(data))
			return (1);
	data->outlen = ft_strlen(data->out);
	return (0);
}
