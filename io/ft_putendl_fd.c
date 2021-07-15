/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:37:30 by fdiego            #+#    #+#             */
/*   Updated: 2021/07/15 18:27:49 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

int	ft_putendl_fd(char const *s, int fd)
{
	return (ft_putstr_fd(s, fd) + write(fd, "\n", 1));
}
