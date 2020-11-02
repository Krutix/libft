/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:36:51 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 18:18:00 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "include/ft_io.h"

static void	rec_print__(unsigned int nb, int fd)
{
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
		return ;
	}
	rec_print__(nb / 10, fd);
	rec_print__(nb % 10, fd);
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
		write(fd, "-", 1);
	rec_print__(nb < 0 ? -nb : nb, fd);
}
