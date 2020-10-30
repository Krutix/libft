
#include "unistd.h"

char	to_hex(unsigned int ch)
{
	if (ch < 0)
		ch *= -1;
	if (ch < 10)
		return (ch + '0');
	else
		return (ch + 'a' - 10);
}

void	print_hex_code(unsigned long long ch)
{
	char b;

	b = to_hex(ch / 16);
	write(1, &b, 1);
	b = to_hex(ch % 16);
	write(1, &b, 1);
}

void	put_hexnbr(unsigned long long nb)
{
	char pr;

	if (nb < 16)
	{
		pr = to_hex(nb);
		write(1, &pr, 1);
		return ;
	}
	put_hexnbr(nb / 16);
	pr = to_hex(nb % 16);
	write(1, &pr, 1);
}

void	print_address(void *addr, int size)
{
	int					size_adds;
	unsigned long long	buff;
	int					i;

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

void	print_data(void *addr, int size)
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

void	ft_print_memory(void *addr, unsigned int size)
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
