/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixprec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:40:44 by okraus            #+#    #+#             */
/*   Updated: 2023/11/18 16:41:41 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static void	ft_round_loop(char *str, int *last, int *carry)
{
	while (*carry && *last && str[*last - 1] != '-')
	{
		*carry = 0;
		--(*last);
		if (str[(*last)] == '9')
		{
			str[(*last)] = '0';
			*carry = 1;
		}
		else if (str[(*last)] != '.' && str[(*last)] != '-')
			str[(*last)]++;
		else if (str[(*last)] == '.')
			*carry = 1;
	}
}

static void	ft_round_string(char *str)
{
	int	last;
	int	carry;

	last = 0;
	carry = 0;
	while (str[last])
		last++;
	--last;
	if (ft_strchr("56789", str[last]))
		carry = 1;
	ft_round_loop(str, &last, &carry);
	while (str[last])
		last++;
	if (!carry)
		str[--last] = '\0';
	else
	{
		while (--last && str[last] != '-')
		{
			str[last] = str[last - 1];
		}
		if (str[0] != '-' && last)
			last--;
		str[last] = '1';
	}
}

static void	ft_process_prec(char *s, char *str, int w, int prec)
{
	int	i;

	i = 0;
	while (s[i] && i < w + prec + 1)
	{
		str[i] = s[i];
		i++;
	}
	if (!s[i])
	{
		while (i < w + prec + 1)
			str[i++] = '0';
	}
	else
	{
		str[i] = s[i];
		ft_round_string(str);
	}
	i = 0;
	if (!prec)
		while (str[++i] != 0)
			if (str[i] == '.')
				str[i] = 0;
}

int	ft_fix_prec(t_pf_info *data)
{
	int		w;
	int		d;
	int		i;
	char	*str;

	i = 0;
	if (!data->out)
		return (1);
	while (data->out[i] && data->out[i] != '.')
		i++;
	if (!data->out[i])
		return (1);
	w = i++;
	d = 0;
	while (data->out[i + d])
		d++;
	str = ft_calloc(w + data->precision + 3, sizeof(char));
	if (!str)
		return (1);
	ft_process_prec(data->out, str, w, data->precision);
	free(data->out);
	data->out = str;
	return (0);
}
