/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:22:52 by okraus            #+#    #+#             */
/*   Updated: 2023/10/15 13:42:08 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static char	*ft_strjoin_printf(char *s1, t_pf_info *data, int len)
{
	int		i;
	int		j;
	char	*s3;

	j = len;
	i = data->outlen;
	s3 = (char *)malloc((i + j + 1) * sizeof(char));
	if (s3 == NULL)
		return (free(s1), NULL);
	s3[i + j] = 0;
	j = 0;
	while (j < len)
	{
		s3[j] = s1[j];
		j++;
	}
	i = 0;
	while (i < data->outlen)
	{
		s3[i + j] = data->out[i];
		i++;
	}
	s3[i + j] = 0;
	return (free(s1), s3);
}

// need special strjoin for 0 characters
char	*ft_print_lst_to_string(t_list *lst, int *len)
{
	t_pf_info	*data;
	char		*str;

	if (!lst)
		return (NULL);
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (lst)
	{
		if (!str)
			return (NULL);
		data = lst->content;
		if (data->out)
			str = ft_strjoin_printf(str, data, *len);
		*len += data->outlen;
		lst = lst->next;
	}
	return (str);
}
