/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:23:54 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 23:21:41 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "ft_io.h"
#include "ft_string.h"
#include "ft_math.h"

static size_t	ft_unum_size(ullint n, size_t base_size)
{
	size_t i;

	i = 1;
	while (n >= base_size)
	{
		i++;
		n /= base_size;
	}
	return (i);
}

int		ft_putnbr_base_fd(llint nb, char *base, int fd)
{
	const size_t	base_size = ft_strlen(base);
	const size_t	len = ft_unum_size(ft_abs(nb), base_size) + (nb < 0);
	ullint			unb;
	char			str_num[len];
	char			*back;

	str_num[0] = '-';
	back = str_num + len - 1;
	unb = ft_abs(nb);
	while (unb >= base_size)
	{
		*back-- = base[unb % base_size];
		unb /= base_size;
	}
	*back = base[unb];
	return (write(fd, str_num, len));
}
