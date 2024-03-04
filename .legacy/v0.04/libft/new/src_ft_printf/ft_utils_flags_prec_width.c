/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_flags_prec_width.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:34:41 by okraus            #+#    #+#             */
/*   Updated: 2023/10/14 11:12:19 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_signed_flags(t_pf_info *data)
{
	if (ft_strlen(data->out) == data->field_width
		&& data->flag & ZERO && data->out[0] == '0'
		&& data->field_width != data->precision)
	{
		if (data->value.ll < 0)
			data->out[0] = '-';
		else if (data->flag & PLUS)
			data->out[0] = '+';
		else if (data->flag & SPACE)
			data->out[0] = ' ';
		if (!data->out)
			return (1);
	}
	else
	{
		if (data->value.ll < 0)
			data->out = ft_strjoin_freeright("-", data->out);
		else if (data->flag & PLUS)
			data->out = ft_strjoin_freeright("+", data->out);
		else if (data->flag & SPACE)
			data->out = ft_strjoin_freeright(" ", data->out);
		if (!data->out)
			return (1);
	}
	return (0);
}

// 0x1001000 x or p
int	ft_unsigned_flags(t_pf_info *data)
{
	if (data->flag & HASHTAG || data->type_flag & LOWERCASE_P)
	{
		if (data->type_flag & LOWERCASE_O)
			data->out = ft_strjoin_freeright("0", data->out);
		else if (data->type_flag & 0x1001000)
		{
			data->out = ft_strjoin_freeright("0x", data->out);
		}
		else if (data->type_flag & UPPERCASE_X)
			data->out = ft_strjoin_freeright("0X", data->out);
		else if (data->type_flag & UPPERCASE_B)
		{
			if (data->baselen == 2)
				data->out = ft_strjoin_freeright("0b", data->out);
			else
				data->out = ft_strjoin_freeright("0B", data->out);
		}
		if (!data->out)
			return (1);
	}
	return (0);
}

int	ft_field_width(t_pf_info *data)
{
	int	i;
	int	err;

	i = data->field_width - ft_strlen(data->out);
	err = 0;
	if (data->flag & ZERO && !(data->flag & PERIOD))
	{
		if (data->flag & MINUS)
			err = ft_padright(i, ' ', &data->out);
	}
	else
	{
		if (data->flag & MINUS)
			err = ft_padright(i, ' ', &data->out);
		else
			err = ft_padleft(i, ' ', &data->out);
	}
	return (err);
}

int	ft_process_precision(t_pf_info *data)
{
	int	i;

	if (data->flag & PERIOD || (data->flag & ZERO && !(data->flag & 0x84)))
	{
		i = data->precision - ft_strlen(data->out);
		if (!(data->flag & PERIOD))
			i = data->field_width - ft_strlen(data->out);
		if (i > 0)
			if (ft_padleft(i, '0', &data->out))
				return (1);
		if (data->flag & PERIOD && !data->precision && !data->value.ull)
		{
			free(data->out);
			data->out = ft_strdup("");
		}
	}
	return (0);
}
