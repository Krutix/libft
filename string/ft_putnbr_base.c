/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:23:54 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/01 20:22:34 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	putch_base(int ch, char *base)
{
	write(1, &base[ch], 1);
}

void	rec_print_base(unsigned int nb, int base_size, char *base)
{
	if (nb < base_size)
	{
		putch_base(nb, base);
		return ;
	}
	rec_print_base(nb / base_size, base_size, base);
	rec_print_base(nb % base_size, base_size, base);
}

void	ft_putnbr_base(int nb, char *base)
{
	int base_size;
	int i;

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
		write(1, "-", 1);
	rec_print_base(nb < 0 ? -nb : nb, base_size, base);
}
