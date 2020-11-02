/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:23:54 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 18:25:35 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	putch_base(int ch, char *base, int fd)
{
	write(fd, &base[ch], 1);
}

void	rec_print_base(unsigned int nb, size_t base_size, char *base, int fd)
{
	if (nb < base_size)
	{
		putch_base(nb, base, fd);
		return ;
	}
	rec_print_base(nb / base_size, base_size, base, fd);
	rec_print_base(nb % base_size, base_size, base, fd);
}

void	ft_putnbr_base_fd(int nb, char *base, int fd)
{
	size_t	base_size;
	size_t	i;

	base_size = 0;
	while (base[base_size])
	{
		if (base[base_size] == '-' || base[base_size] == '+')
			return ;
		i = -1;
		while (++i < base_size)
			if (base[i] == base[base_size])
				return ;
		base_size++;
	}
	if (base_size < 2)
		return ;
	if (nb < 0)
		write(fd, "-", 1);
	rec_print_base(nb < 0 ? -nb : nb, base_size, base, fd);
}
