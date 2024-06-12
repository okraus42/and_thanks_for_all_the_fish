/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_other.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:40:36 by okraus            #+#    #+#             */
/*   Updated: 2023/10/13 17:42:08 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

//	0x84 PERIOD & MINUS
int	ft_process_prcint(t_pf_info *data)
{
	char	*temp;

	data->out = ft_ltoa_base(data->value.ll, BASE_CAP, 10);
	if (!data->out)
		return (1);
	if (data->out[0] == '-')
	{
		temp = data->out;
		data->out = ft_strdup(&data->out[1]);
		free(temp);
		if (!data->out)
			return (1);
	}
	if (data->flag & PERIOD || (data->flag & ZERO && !(data->flag & 0x84)))
		if (ft_process_precision(data))
			return (1);
	if (ft_signed_flags(data))
		return (1);
	if (data->field_width > ft_strlen(data->out))
		if (ft_field_width(data))
			return (1);
	data->outlen = ft_strlen(data->out);
	return (0);
}

int	ft_process_prc(t_pf_info *data)
{
	data->out = ft_strdup("%");
	data->outlen = 1;
	return (0);
}

int	ft_process_prcchr(t_pf_info *data)
{
	char	s[2];
	int		err;

	s[0] = (char)data->value.i;
	s[1] = 0;
	err = 0;
	data->out = ft_strdup(s);
	if (!data->out)
		return (1);
	if (data->field_width > 1)
	{
		if (data->flag & MINUS)
			err = ft_padright_char(data->field_width, ' ', &data->out);
		else
			err = ft_padleft_char(data->field_width, ' ', &data->out);
		data->outlen = data->field_width;
	}
	else
		data->outlen = 1;
	return (err);
}

int	ft_process_prcstr(t_pf_info *data)
{
	if (!data->value.s && (data->precision >= 6U || !(data->flag & PERIOD)))
		data->out = ft_strdup("(null)");
	else if (!data->value.s)
		data->out = ft_strdup("");
	else if (data->flag & PERIOD)
		data->out = ft_string_copy_n(data->value.s, data->precision);
	else
		data->out = ft_stringcopy(data->value.s);
	if (!data->out)
		return (1);
	if (data->field_width > ft_strlen(data->out))
		if (ft_field_width(data))
			return (1);
	data->outlen = ft_strlen(data->out);
	return (0);
}

int	ft_process_prcptr(t_pf_info *data)
{
	data->value.ull = (unsigned long long)data->value.p;
	if (!data->value.p)
		data->out = ft_strdup("(nil)");
	else
		data->out = ft_ultoa_base(data->value.ull, BASE_SML, 16);
	if (!data->out)
		return (1);
	if (data->value.p && ft_unsigned_flags(data))
		return (1);
	if (data->field_width > ft_strlen(data->out))
		if (ft_field_width(data))
			return (1);
	data->outlen = ft_strlen(data->out);
	return (0);
}
