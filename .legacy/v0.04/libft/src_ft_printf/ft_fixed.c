/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:51:35 by okraus            #+#    #+#             */
/*   Updated: 2023/11/18 16:41:33 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_process_prcfix(t_pf_info *data)
{
	char	*temp;

	data->out = ft_fixtoa(data->value.ll, data->baselen);
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
		if (ft_fix_prec(data))
			return (1);
	if (ft_signed_flags(data))
		return (1);
	if (data->field_width > ft_strlen(data->out))
		if (ft_field_width(data))
			return (1);
	data->outlen = ft_strlen(data->out);
	return (0);
}
