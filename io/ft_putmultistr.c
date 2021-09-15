/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmultistr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:07:56 by CWatcher          #+#    #+#             */
/*   Updated: 2021/09/15 23:18:02 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

ssize_t	ft_putmultistr(char *const mutlistring[])
{
	ssize_t	r;
	ssize_t	ret;

	r = 0;
	ret = 0;
	while (*mutlistring && r >= 0)
	{
		r = ft_putendl(*mutlistring++);
		if (r < 0)
			ret = r;
		else
			ret += r;
	}
	return (ret);
}
