/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:07:56 by CWatcher          #+#    #+#             */
/*   Updated: 2021/10/07 22:51:48 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"

ssize_t	ft_putstr(const char *s)
{
	return (write(STDOUT_FILENO, s, ft_strlen(s) * sizeof(*s)));
}

ssize_t	ft_putstr_s(const char *s)
{
	if (!s)
		return (0);
	return (ft_putstr(s));
}
