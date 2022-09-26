/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:18:17 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 10:30:13 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	alloc = malloc(count * size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, count * size);
	return (alloc);
}
