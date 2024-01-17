/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:48:36 by okraus            #+#    #+#             */
/*   Updated: 2023/10/13 17:56:56 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_add_node(t_list **head, const char *s, int type, int *end)
{
	t_list		*lst;
	t_pf_info	*data;

	data = ft_calloc(sizeof(t_pf_info), 1);
	if (!data)
		return (1);
	data->orig = s;
	data->type = type & 1;
	*end = type;
	lst = ft_lstnew(data);
	if (!lst)
	{
		free(data);
		return (1);
	}
	ft_lstadd_back(head, lst);
	return (0);
}

t_list	*ft_process_input_string(const char *s)
{
	int		i;
	int		error;
	int		end;
	t_list	*head;

	i = 0;
	end = 2;
	head = NULL;
	error = 0;
	while (s[i] && !error)
	{
		if (end & 1 && ft_strchr(F_TYPES, s[i]))
			end = 2;
		else if (s[i] == '%')
			error = ft_add_node(&head, &s[i], 1, &end);
		else if (end & 2)
			error = ft_add_node(&head, &s[i], 0, &end);
		++i;
	}
	if (error)
	{
		ft_lstclear(&head, ft_clear_pf_data);
		return (NULL);
	}
	return (head);
}

static void	ft_init_flags_helper(int flag, t_pf_info *data)
{
	data->flag |= flag;
}

void	ft_init_flags(int *i, t_pf_info *data)
{
	while (data->orig[*i] && ft_strchr(F_FLAGS, data->orig[*i]))
	{
		if (data->orig[*i] == '0')
			ft_init_flags_helper(ZERO, data);
		else if (data->orig[*i] == '#')
			ft_init_flags_helper(HASHTAG, data);
		else if (data->orig[*i] == '-')
			ft_init_flags_helper(MINUS, data);
		else if (data->orig[*i] == '+')
			ft_init_flags_helper(PLUS, data);
		else if (data->orig[*i] == ' ')
			ft_init_flags_helper(SPACE, data);
		else if (data->orig[*i] == '\'')
			ft_init_flags_helper(APOSTROPHE, data);
		else if (data->orig[*i] == 'I')
			ft_init_flags_helper(UPPERCASE_I, data);
		++(*i);
	}
}

void	ft_init_field_width(int *i, int *err, t_pf_info *data, va_list arg)
{
	int			n;
	long long	num;

	if (data->orig[*i] == '*')
	{
		data->field_width = va_arg(arg, unsigned int);
		++(*i);
	}
	else
	{
		n = 0;
		num = ft_latoi(&data->orig[*i]);
		while (ft_isdigit(data->orig[*i]))
		{
			++n;
			++(*i);
		}
		if (n > 15 || num > 0xFFFFFFFF)
			*err = 1;
		else
			data->field_width = (unsigned int)num;
	}
}
