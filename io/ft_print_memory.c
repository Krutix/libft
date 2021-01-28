/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:16:35 by fdiego            #+#    #+#             */
/*   Updated: 2021/01/28 17:16:40 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "ft_io.h"
#include "memory.h"

static void		print_hex_code(unsigned long long ch)
{
	char b;

	b = "0123456789abcdef"[ch / 16];
	write(1, &b, 1);
	b = "0123456789abcdef"[ch % 16];
	write(1, &b, 1);
}

static void		put_hexnbr(unsigned long long nb)
{
	if (nb < 16)
	{
		ft_putchar_fd("0123456789abcdef"[nb], 1);
		return ;
	}
	put_hexnbr(nb / 16);
	ft_putchar_fd("0123456789abcdef"[nb % 16], 1);
}

static void		print_address(void *addr, size_t size)
{
	size_t				size_adds;
	unsigned long long	buff;
	size_t				i;

	buff = (unsigned long long)addr;
	size_adds = 0;
	while (buff > 0)
	{
		buff /= 16;
		size_adds++;
	}
	while (size_adds++ < 16)
		write(1, "0", 1);
	put_hexnbr((unsigned long long)addr);
	write(1, ": ", 2);
	i = 0;
	while (i < size)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		print_hex_code(*(char*)(addr + i));
		i++;
	}
}

static void		print_data(void *addr, int size)
{
	int i;

	i = size;
	while (i < 18)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (*(char*)(addr + i) <= '\x1f' || *(char*)(addr + i) == '\x7f')
			write(1, ".", 1);
		else
			write(1, addr + i, 1);
		i++;
	}
}

void			ft_print_memory(void *addr, size_t size)
{
	while (size > 16)
	{
		print_address(addr, 16);
		print_data(addr, 16);
		write(1, "\n", 1);
		size -= 16;
		addr += 0x10;
	}
	if (size != 0)
	{
		print_address(addr, size);
		print_data(addr, size);
	}
	write(1, "\n", 1);
}
