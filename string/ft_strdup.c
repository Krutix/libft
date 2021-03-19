/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:07:13 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:38:38 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

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
