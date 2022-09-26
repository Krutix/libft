/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmultistr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 21:07:56 by CWatcher          #+#    #+#             */
/*   Updated: 2021/10/11 23:50:39 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

ssize_t	ft_putmultistr_fd(char *const mutlistring[], int fd)
{
	ssize_t	r;
	ssize_t	ret;

	r = 0;
	ret = 0;
	if (!mutlistring || !*mutlistring)
		return (0);
	while (*mutlistring && r >= 0)
	{
		r = ft_putendl_fd_s(*mutlistring++, fd);
		if (r < 0)
			ret = r;
		else
			ret += r;
	}
	return (ret);
}
