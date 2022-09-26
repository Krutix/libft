/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmultistr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:07:56 by CWatcher          #+#    #+#             */
/*   Updated: 2021/10/11 23:51:08 by CWatcher         ###   ########.fr       */
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
	if (!mutlistring || !*mutlistring)
		return (0);
	while (*mutlistring && r >= 0)
	{
		r = ft_putendl_s(*mutlistring++);
		if (r < 0)
			ret = r;
		else
			ret += r;
	}
	return (ret);
}
