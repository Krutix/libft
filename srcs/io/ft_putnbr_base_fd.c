/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:23:54 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 11:21:20 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "ft_io.h"
#include "ft_string.h"
#include "ft_math.h"

static size_t	ft_unum_size(t_ullint n, size_t base_size)
{
	size_t	i;

	i = 1;
	while (n >= base_size)
	{
		i++;
		n /= base_size;
	}
	return (i);
}

int	ft_putnbr_base_fd(t_llint nb, char *base, int fd)
{
	const size_t	base_length = ft_strlen(base);
	const size_t	len = ft_unum_size(ft_abs(nb), base_length) + (nb < 0);
	t_ullint		unb;
	char			str_num[64];
	char			*back;

	str_num[0] = '-';
	back = str_num + len - 1;
	unb = ft_abs(nb);
	while (unb >= base_length)
	{
		*back-- = base[unb % base_length];
		unb /= base_length;
	}
	*back = base[unb];
	return (write(fd, str_num, len));
}
