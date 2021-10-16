/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:07:13 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/07 22:17:53 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strdup_s(char const *src)
{
	if (src == NULL)
		return (NULL);
	return (ft_strdup(src));
}

char	*ft_strdup(char const *src)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(src);
	copy = malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, src, len + 1);
	return (copy);
}
