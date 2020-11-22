/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:36:51 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 23:05:23 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"
#include "ft_math.h"
#include "ftdef.h"

int		ft_putnbr_fd(llint nb, int fd)
{
	return (ft_putnbr_base_fd(nb, "0123456789", fd));
}
