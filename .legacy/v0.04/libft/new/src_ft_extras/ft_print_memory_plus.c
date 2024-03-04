/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory_plus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:42:15 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:12:19 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static void	ft_format_plus(int fd, unsigned char c)
{
	if (c == 0)
		write(fd, "\033[0m", 4);
	else if (c < 32 || c == 127)
		write(fd, "\033[97;44m", 8);
	else if (c < 127)
		write(fd, "\033[92;40m", 8);
	else
		write(fd, "\033[1;41m", 7);
}

static void	ft_putaddr_fd(uintptr_t mem, int fd, unsigned int k)
{
	unsigned long	f;
	unsigned int	i;
	unsigned char	c;
	unsigned char	*s;

	i = 0;
	c = 0;
	s = (unsigned char *) mem;
	f = 0xF000000000000000;
	while (i < 16 && k)
	{
		if (s[i] > c)
			c = s[i];
		if (s[i] && s[i] < 32 && c < 127)
			c = 127;
		i++;
	}
	i = 0;
	ft_format_plus(fd, c);
	while (i < 16)
	{
		write(fd, &"0123456789abcdef"[((mem & f) / 0x1000000000000000)], 1);
		mem <<= 4;
		i++;
	}
}

static void	ft_put_hex(void *addr, int fd, unsigned int k)
{
	unsigned int	i;
	unsigned char	*s;

	write(fd, ":\033[0m ", 6);
	i = 0;
	s = (unsigned char *) addr;
	while (i < 16)
	{
		if (k)
		{
			ft_format_plus(fd, s[i]);
			write(fd, &"0123456789ABCDEF"[s[i] / 16], 1);
			write(fd, &"0123456789ABCDEF"[s[i] % 16], 1);
			write(fd, "\033[0m", 4);
			k--;
		}
		else
			write(fd, "\033[0m  ", 6);
		if (i & 1)
			write(fd, "\033[0m ", 5);
		i++;
	}
}

static void	ft_put_char(void *addr, int fd, unsigned int k)
{
	unsigned int	i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *) addr;
	while (k && i < 16)
	{
		ft_format_plus(fd, s[i]);
		if (s[i] > 31 && s[i] < 127)
		{
			write(fd, &s[i], 1);
			write(fd, "\033[0m", 4);
		}
		else
			write(fd, ".\033[0m", 5);
		k--;
		i++;
	}
	write(fd, "\033[0m", 4);
	write(fd, "\n", 1);
}

void	*ft_print_memory_plus(void *addr, int fd, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	while (i < size)
	{
		k = size - i;
		ft_putaddr_fd((uintptr_t) addr + i, fd, k);
		ft_put_hex(addr + i, fd, k);
		ft_put_char(addr + i, fd, k);
		i += 16;
	}
	return (addr);
}

/*
static void	ft_put_char_2(void *addr, int fd, unsigned int k)
{
	unsigned int	i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *) addr;
	while (k && i < 16)
	{
		if (s[i])
		{
			ft_putaddr_fd((uintptr_t) addr + i, fd);
			write(fd, &s[i], 1);
			write(fd, "\n", 1);
		}
		k--;
		i++;
	}
}

void	*ft_print_memory_2(void *addr, int fd, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	while (i < size)
	{
		k = size - i;
		ft_put_char_2(addr + i, fd, k);
		i += 16;
	}
	return (addr);
}
*/
