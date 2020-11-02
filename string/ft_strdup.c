/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:07:13 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 18:21:53 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "include/ft_string.h"

char	*ft_strdup(char *src)
{
	unsigned int	len;
	char			*copy;

	len = 0;
	while (src[len])
		len++;
	copy = malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	len = 0;
	while (src[len])
	{
		copy[len] = src[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}
