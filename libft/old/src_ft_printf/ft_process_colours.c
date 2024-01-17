/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_colours.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:17:58 by okraus            #+#    #+#             */
/*   Updated: 2023/10/14 14:33:43 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_strjoin_freeleft2(t_pf_info *data, char const *s2)
{
	data->out = ft_strjoin_freeleft(data->out, s2);
	if (!(data->out))
		return (1);
	return (0);
}

static int	ft_process_prcclr_flags(t_pf_info *data)
{
	if (data->field_width & 0x1)
		if (ft_strjoin_freeleft2(data, "1;"))
			return (1);
	if (data->field_width & 0x2)
		if (ft_strjoin_freeleft2(data, "2;"))
			return (1);
	if (data->field_width & 0x4)
		if (ft_strjoin_freeleft2(data, "3;"))
			return (1);
	if (data->field_width & 0x8)
		if (ft_strjoin_freeleft2(data, "4;"))
			return (1);
	if (data->field_width & 0x10)
		if (ft_strjoin_freeleft2(data, "5;"))
			return (1);
	if (data->field_width & 0x20)
		if (ft_strjoin_freeleft2(data, "7;"))
			return (1);
	if (data->field_width & 0x40)
		if (ft_strjoin_freeleft2(data, "8;"))
			return (1);
	if (data->field_width & 0x80)
		if (ft_strjoin_freeleft2(data, "9;"))
			return (1);
	return (0);
}

static int	ft_process_prcclr_text(t_pf_info *data, char *r, char *g, char *b)
{
	r = ft_itoa((data->precision >> 16) & 0xFF);
	g = ft_itoa((data->precision >> 8) & 0xFF);
	b = ft_itoa(data->precision & 0xFF);
	if (!r || !g || !b)
		return (1);
	r = ft_strjoin_freeleft(r, ";");
	g = ft_strjoin_freeleft(g, ";");
	b = ft_strjoin_freeleft(b, ";");
	if (!r || !g || !b)
		return (1);
	data->out = ft_strjoin_freeleft(data->out, "38;2;");
	if (!data->out)
		return (1);
	data->out = ft_strjoin_freeboth(data->out, r);
	if (!data->out)
		return (1);
	data->out = ft_strjoin_freeboth(data->out, g);
	if (!data->out)
		return (1);
	data->out = ft_strjoin_freeboth(data->out, b);
	if (!data->out)
		return (1);
	return (0);
}

static int	ft_process_prcclr_bgr(t_pf_info *data, char *r, char *g, char *b)
{
	r = ft_itoa((data->baselen >> 16) & 0xFF);
	g = ft_itoa((data->baselen >> 8) & 0xFF);
	b = ft_itoa(data->baselen & 0xFF);
	if (!r || !g || !b)
		return (1);
	r = ft_strjoin_freeleft(r, ";");
	g = ft_strjoin_freeleft(g, ";");
	b = ft_strjoin_freeleft(b, ";");
	if (!r || !g || !b)
		return (1);
	data->out = ft_strjoin_freeleft(data->out, "48;2;");
	if (!data->out)
		return (1);
	data->out = ft_strjoin_freeboth(data->out, r);
	if (!data->out)
		return (1);
	data->out = ft_strjoin_freeboth(data->out, g);
	if (!data->out)
		return (1);
	data->out = ft_strjoin_freeboth(data->out, b);
	if (!data->out)
		return (1);
	return (0);
}

int	ft_process_prcclr(t_pf_info *data)
{
	data->out = ft_strdup("\033[");
	if (data->field_width)
		if (ft_process_prcclr_flags(data))
			return (1);
	if (data->flag & PERIOD)
		if (ft_process_prcclr_text(data, data->red, data->green, data->blue))
			return (1);
	if (data->flag & CIRCUMFLEX)
		if (ft_process_prcclr_bgr(data, data->red, data->green, data->blue))
			return (1);
	if (!data->field_width && !(data->flag & 0x180))
		data->out = ft_strjoin_freeleft(data->out, "0;");
	if (!data->out)
		return (1);
	data->out[ft_strlen(data->out) - 1] = 'm';
	if (!data->out)
		return (1);
	data->outlen = ft_strlen(data->out);
	return (0);
}
