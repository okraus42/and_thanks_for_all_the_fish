/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:34:38 by okraus            #+#    #+#             */
/*   Updated: 2023/10/15 11:35:49 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_get_print_string(va_list arg, const char *s, int *len)
{
	char	*str;
	t_list	*lst;

	lst = ft_process_input_string(s);
	str = NULL;
	if (ft_init_list(arg, lst))
	{
		ft_lstclear(&lst, ft_clear_pf_data);
		lst = NULL;
	}
	if (ft_process_list(lst))
	{
		ft_lstclear(&lst, ft_clear_pf_data);
		lst = NULL;
	}
	str = ft_print_lst_to_string(lst, len);
	if (lst)
		ft_lstclear(&lst, ft_clear_pf_data);
	return (str);
}

void	ft_print_list(t_list *lst)
{
	t_pf_info	*data;

	while (lst)
	{
		data = lst->content;
		if (data)
		{
			if (data->orig)
			{
				ft_printf("string: %s\n", data->orig);
			}
			else
				write(1, "string not found", 16);
			ft_printf("data type: %i\n", data->type);
			ft_printf("flag: %x\n", data->flag);
			ft_printf("value_flag: %x\n", data->value_flag);
			ft_printf("type_flag: %x\n", data->type_flag);
			ft_printf("value: %i\n", data->value.i);
			ft_printf("width: %x\n", data->field_width);
			ft_printf("precision: %x\n", data->precision);
		}
		else
			write(1, "data not found\n", 15);
		lst = lst->next;
	}
}
