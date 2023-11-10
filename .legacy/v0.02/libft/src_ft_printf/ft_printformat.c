/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:30:53 by okraus            #+#    #+#             */
/*   Updated: 2023/06/17 14:53:19 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_check_end(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X'
		|| c == 'B' || c == 'P' || c == 'C' || c == '%'
		|| c == '\0')
		return (0);
	else
		return (1);
}

void	ft_dash_struct(t_output *t, int n)
{
	if (n == 1)
	{
		t->dash = 1;
		t->zero = 0;
	}
	if (n == 2)
	{
		t->period = 1;
		t->zero = 0;
	}
}

void	ft_initialise_struct(t_output *t)
{
	t->string = NULL;
	t->len = 0;
	t->precision = 0;
	t->padsize = 0;
	t->dash = 0;
	t->zero = 0;
	t->period = 0;
	t->hash = 0;
	t->space = 0;
	t->plus = 0;
	t->type = 0;
	t->base = 0;
}

int	ft_get_num(t_output *t, const char *s, int i)
{
	int	j;

	j = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		j = j * 10 + s[i] - '0';
		i++;
	}
	if (t->period == 1)
	{
		t->precision = j;
	}
	else
	{
		t->padsize = j;
	}
	return (i);
}

void	ft_prefill_struct(t_output *t, const char *s)
{
	int	i;

	i = 0;
	while (ft_check_end(s[i]))
	{
		if (s[i] == '%')
			break ;
		if (s[i] == ' ')
			t->space = 1;
		if (s[i] == '#')
			t->hash = 1;
		if (s[i] == '+')
			t->plus = 1;
		if (s[i] == '-')
			ft_dash_struct(t, 1);
		if (s[i] == '.')
			ft_dash_struct(t, 2);
		if (s[i] == '0' && !t->dash)
			t->zero = 1;
		if (s[i] > '0' && s[i] <= '9')
			i = ft_get_num(t, s, i);
		else
			i++;
	}
}
