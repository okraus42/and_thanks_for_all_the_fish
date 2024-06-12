/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:48:42 by okraus            #+#    #+#             */
/*   Updated: 2023/10/13 17:54:58 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

//unsigned char and unsigned short promoted to unsigned int
static void	ft_get_unsigned_int_value_helper(t_pf_info *data,
	va_list arg, int flag)
{
	data->value_flag = flag;
	if (flag & UNSIGNED_CHAR)
		data->value.ull = va_arg(arg, unsigned int);
	else if (flag & UNSIGNED_SHORT)
		data->value.ull = va_arg(arg, unsigned int);
	else if (flag & UNSIGNED_LONG)
		data->value.ull = va_arg(arg, unsigned long);
	else if (flag & UNSIGNED_LONG_LONG)
		data->value.ull = va_arg(arg, unsigned long long);
	else if (flag & SIZE_T)
		data->value.ull = va_arg(arg, size_t);
	else if (flag & UNSIGNED_INT)
		data->value.ull = va_arg(arg, unsigned int);
}

int	ft_get_unsigned_int_value(t_pf_info *data, va_list arg)
{
	if (data->type_flag & LENGTH_MODIFIER)
	{
		if (data->type_flag & LOWERCASE_HH)
			ft_get_unsigned_int_value_helper(data, arg, UNSIGNED_CHAR);
		else if (data->type_flag & LOWERCASE_H)
			ft_get_unsigned_int_value_helper(data, arg, UNSIGNED_SHORT);
		else if (data->type_flag & LOWERCASE_L)
			ft_get_unsigned_int_value_helper(data, arg, UNSIGNED_LONG);
		else if (data->type_flag & LLL)
			ft_get_unsigned_int_value_helper(data, arg, UNSIGNED_LONG_LONG);
		else if (data->type_flag & LOWERCASE_Z)
			ft_get_unsigned_int_value_helper(data, arg, SIZE_T);
		else
			return (1);
	}
	else
		ft_get_unsigned_int_value_helper(data, arg, UNSIGNED_INT);
	return (0);
}

int	ft_init_unsigned(char c, t_pf_info *data, va_list arg)
{
	if (c == 'o')
		data->type_flag |= LOWERCASE_O;
	else if (c == 'u')
		data->type_flag |= LOWERCASE_U;
	else if (c == 'x')
		data->type_flag |= LOWERCASE_X;
	else if (c == 'X')
		data->type_flag |= UPPERCASE_X;
	else if (c == 'b')
		data->type_flag |= LOWERCASE_B;
	else if (c == 'B')
		data->type_flag |= UPPERCASE_B;
	return (ft_get_unsigned_int_value(data, arg));
}

//float promoted to double
int	ft_get_double_value(t_pf_info *data, va_list arg)
{
	if (data->type_flag & LENGTH_MODIFIER)
	{
		if (data->type_flag & LLL)
		{
			data->value_flag = LONG_DOUBLE;
			data->value.ld = va_arg(arg, long double);
		}
		else if (data->type_flag & LOWERCASE_L)
		{
			data->value_flag = DOUBLE;
			data->value.d = va_arg(arg, double);
		}
		else
			return (1);
	}
	else
	{
		data->value_flag = DOUBLE;
		data->value.d = va_arg(arg, double);
	}
	return (0);
}

int	ft_init_double(char c, t_pf_info *data, va_list arg)
{
	if (c == 'e')
		data->type_flag |= LOWERCASE_E;
	else if (c == 'E')
		data->type_flag |= UPPERCASE_E;
	else if (c == 'f')
		data->type_flag |= LOWERCASE_F;
	else if (c == 'F')
		data->type_flag |= UPPERCASE_F;
	else if (c == 'g')
		data->type_flag |= LOWERCASE_G;
	else if (c == 'G')
		data->type_flag |= UPPERCASE_G;
	else if (c == 'a')
		data->type_flag |= LOWERCASE_A;
	else if (c == 'A')
		data->type_flag |= UPPERCASE_A;
	return (ft_get_double_value(data, arg));
}
