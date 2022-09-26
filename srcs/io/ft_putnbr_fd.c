/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:36:51 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 11:22:28 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"
#include "ft_math.h"
#include "ftdef.h"

int	ft_putnbr_fd(t_llint nb, int fd)
{
	return (ft_putnbr_base_fd(nb, "0123456789", fd));
}
