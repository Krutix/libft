/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemultistr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:05:26 by CWatcher          #+#    #+#             */
/*   Updated: 2021/09/23 18:05:29 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_freemultistr(char **ps)
{
	char	**pp;

	if (!ps)
		return (NULL);
	pp = ps;
	while (*ps)
		free(*ps++);
	free(pp);
	return (NULL);
}
