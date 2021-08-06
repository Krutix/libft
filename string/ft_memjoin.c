/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:31:23 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:31:23 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "stdlib.h"

void	*ft_memjoin(void const *s1, void const *s2,
							size_t len1, size_t len2)
{
	char	*join_str;

	join_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!join_str)
		return (NULL);
	ft_memcpy(join_str, s1, len1);
	ft_memcpy(join_str + len1, s2, len2);
	join_str[len1 + len2] = '\0';
	return (join_str);
}
