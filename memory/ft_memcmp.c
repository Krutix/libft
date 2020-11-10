/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:00:34 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/09 16:18:54 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "memory.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n-- != 0)
		if (*((unsigned char*)s1++) != *((unsigned char*)s2++))
			return (*((unsigned char*)s1 - 1) - *((unsigned char*)s2 - 1));
	return (0);
}
