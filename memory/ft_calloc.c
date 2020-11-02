/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:18:17 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 18:18:22 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_memory.h"
#include "stdlib.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (!(alloc = malloc(count * size)))
		return (NULL);
	ft_bzero(alloc, count * size);
	return (alloc);
}
