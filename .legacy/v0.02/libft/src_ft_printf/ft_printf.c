/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:49:23 by okraus            #+#    #+#             */
/*   Updated: 2023/08/15 16:07:55 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_putstuff2(va_list arg, const char *s, int *q, t_output *t)
{
	if (s[q[0]] == 'p')
		q[1] += ft_putpointer_fd(va_arg(arg, void *), q[2], t);
	else if (s[q[0]] == 'u')
		q[1] += ft_putunsigned_fd(va_arg(arg, unsigned int), q[2], t);
	else if (s[q[0]] == 'c')
		q[1] += ft_pf_putchar_fd(va_arg(arg, int), q[2], t);
	else if (s[q[0]] == 's')
		q[1] += ft_putstring_fd(va_arg(arg, char *), q[2], t);
	else if (s[q[0]] == 'd' || s[q[0]] == 'i')
		q[1] += ft_putinteger_fd(va_arg(arg, int), q[2], t);
	else if (s[q[0]] == 'X')
		q[1] += ft_puthexabig_fd(va_arg(arg, unsigned int), q[2], t);
	else if (s[q[0]] == 'x')
		q[1] += ft_puthexasmall_fd(va_arg(arg, unsigned int), q[2], t);
	else if (s[q[0]] == 'B')
		q[1] += ft_putbasebig_fd(va_arg(arg, unsigned int), q[2], t);
	else if (s[q[0]] == 'P')
		q[1] += ft_putbinocthex_fd(va_arg(arg, void *), q[2], t);
	else if (s[q[0]] == 'C')
		q[1] += ft_putcolour_fd(q[2], t);
}

void	ft_putstuff(va_list arg, const char *s, int *q, t_output *t)
{
	ft_prefill_struct(t, &s[q[0]]);
	while (s[q[0]] && !ft_strchr(F_TYPS, s[q[0]]))
		q[0]++;
	if (s[q[0]] == '%')
		q[1] += write(q[2], &s[q[0]], 1);
	ft_putstuff2(arg, s, q, t);
	q[0]++;
}

void	ft_writestuff(int fd, const char *s, int *q)
{
	q[1] += write (fd, &s[q[0]], 1);
	q[0]++;
}

int	ft_printf_fd(int fd, const char *s, ...)
{
	static int		q[3];
	va_list			arg;
	static t_output	*t;

	t = (t_output *)malloc(sizeof(t_output));
	if (!t)
		return (-1);
	va_start(arg, s);
	q[0] = 0;
	q[1] = 0;
	q[2] = fd;
	while (s[q[0]])
	{
		if (s[q[0]] == '%')
		{
			ft_initialise_struct(t);
			q[0]++;
			ft_putstuff(arg, s, q, t);
		}
		else
			ft_writestuff(q[2], s, q);
	}
	va_end(arg);
	free (t);
	return (q[1]);
}

int	ft_printf(const char *s, ...)
{
	static int		q[3];
	va_list			arg;
	static t_output	*t;

	t = (t_output *)malloc(sizeof(t_output));
	if (!t)
		return (-1);
	va_start(arg, s);
	q[0] = 0;
	q[1] = 0;
	q[2] = 1;
	while (s[q[0]])
	{
		if (s[q[0]] == '%')
		{
			ft_initialise_struct(t);
			q[0]++;
			ft_putstuff(arg, s, q, t);
		}
		else
			ft_writestuff(1, s, q);
	}
	va_end(arg);
	free (t);
	return (q[1]);
}
