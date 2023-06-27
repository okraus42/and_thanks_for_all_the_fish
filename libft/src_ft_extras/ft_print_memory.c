/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:42:15 by okraus            #+#    #+#             */
/*   Updated: 2023/03/14 15:12:21 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static void	ft_putaddr_fd(uintptr_t mem, int fd)
{
	unsigned long	f;
	unsigned int	i;

	i = 0;
	f = 0xF000000000000000;
	while (i < 16)
	{
		write(fd, &"0123456789abcdef"[((mem & f) / 0x1000000000000000)], 1);
		mem <<= 4;
		i++;
	}
	write(fd, ": ", 2);
}

static void	ft_put_hex(void *addr, int fd, unsigned int k)
{
	unsigned int	i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *) addr;
	while (i < 16)
	{
		if (k)
		{
			write(fd, &"0123456789abcdef"[s[i] / 16], 1);
			write(fd, &"0123456789abcdef"[s[i] % 16], 1);
			k--;
		}
		else
			write(fd, "  ", 2);
		if (i & 1)
			write(fd, " ", 1);
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
		if (s[i] > 31 && s[i] < 127)
		{
			write(fd, &s[i], 1);
		}
		else
			write(fd, ".", 1);
		k--;
		i++;
	}
	write(fd, "\n", 1);
}

void	*ft_print_memory(void *addr, int fd, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	while (i < size)
	{
		k = size - i;
		ft_putaddr_fd((uintptr_t) addr + i, fd);
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
