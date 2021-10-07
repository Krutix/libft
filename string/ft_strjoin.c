/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:32:52 by CWatcher          #+#    #+#             */
/*   Updated: 2021/10/07 22:28:55 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strjoin_s(char const *s1, char const *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	return (ft_strjoin(s1, s2));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s0;
	char	*s;

	s0 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s0)
		return (NULL);
	s = s0;
	while (s1 && *s1)
		*s++ = *s1++;
	while (s2 && *s2)
		*s++ = *s2++;
	*s = '\0';
	return (s0);
}
