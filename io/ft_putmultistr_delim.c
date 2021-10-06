/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmultistr_delim.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:41:14 by CWatcher          #+#    #+#             */
/*   Updated: 2021/10/06 22:56:33 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

ssize_t	ft_putmultistr_delim(char *const multistring[],
								const char *delimiter, const char *ending)
{
	ssize_t	r;
	ssize_t	ret;

	if (!multistring || !*multistring)
		return (0);
	ret = ft_putstr(*multistring);
	if (ret < 0)
		return (ret);
	r = 0;
	while (*++multistring && r >= 0)
	{
		r = ft_putstr(delimiter);
		if (r < 0)
			return (r);
		ret += r;
		r = ft_putstr(*multistring);
		if (r < 0)
			return (r);
		ret += r;
	}
	r = ft_putstr(ending);
	if (r < 0)
		return (r);
	return (ret += r);
}
