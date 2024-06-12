/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:36:53 by okraus            #+#    #+#             */
/*   Updated: 2023/10/13 17:29:51 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_lnumlen_base(long long n, int base)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_ltoa_base(long long n, char *basestr, int baselen)
{
	char				*str;
	int					i;
	unsigned long long	m;

	if (baselen > (int)ft_strlen(basestr) || baselen < 2)
		return (NULL);
	i = ft_lnumlen_base(n, baselen) - 1;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i + 1] = 0;
	str[0] = '-';
	if (n == 0)
		str[i] = basestr[0];
	if (n < 0)
		m = -n;
	else
		m = n;
	while (m != 0)
	{
		str[i] = basestr[m % baselen];
		m = m / baselen;
		i--;
	}
	return (str);
}

static int	ft_ulnumlen_base(unsigned long long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_ultoa_base(unsigned long long n, char *basestr, int baselen)
{
	char	*str;
	int		i;

	if (baselen > (int)ft_strlen(basestr) || baselen < 2)
		return (NULL);
	i = ft_ulnumlen_base(n, baselen) - 1;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i + 1] = 0;
	if (n == 0)
		str[i] = basestr[0];
	while (n != 0)
	{
		str[i] = basestr[n % baselen];
		n = n / baselen;
		i--;
	}
	return (str);
}

void	ft_clear_pf_data(void *vdata)
{
	t_pf_info	*data;

	data = vdata;
	if (data->out)
		free(data->out);
	data->out = NULL;
	free(data);
	data = NULL;
}
