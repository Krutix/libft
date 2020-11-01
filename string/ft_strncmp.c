/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:01:43 by fdiego            #+#    #+#             */
/*   Updated: 2020/10/31 23:56:47 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- != 0 && (*s1 || *s2))
		if (*(unsigned char*)s1++ != *(unsigned char*)s2++)
			return (*(unsigned char*)(s1 - 1) - *(unsigned char*)(s2 - 1));
	return (0);
}
