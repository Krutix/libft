/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:09:06 by CWatcher          #+#    #+#             */
/*   Updated: 2021/10/07 16:58:41 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

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
