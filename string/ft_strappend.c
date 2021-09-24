/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:50:57 by CWatcher          #+#    #+#             */
/*   Updated: 2021/09/23 17:50:13 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strappend(char **ps, const char *s2)
{
	char	*s;

	s = ft_strjoin(*ps, s2);
	free(*ps);
	return (*ps = s);
}
