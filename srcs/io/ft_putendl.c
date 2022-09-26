/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:09:06 by CWatcher          #+#    #+#             */
/*   Updated: 2021/10/07 22:53:38 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

ssize_t	ft_putendl_s(const char *s)
{
	ssize_t	r;

	r = ft_putstr_s(s);
	if (r < 0)
		return (-1);
	if (ft_putstr("\n") < 0)
		return (-1);
	return (r + sizeof(char));
}

ssize_t	ft_putendl(const char *s)
{
	ssize_t	r;

	r = ft_putstr(s);
	if (r < 0)
		return (-1);
	if (ft_putstr("\n") < 0)
		return (-1);
	return (r + sizeof(char));
}
