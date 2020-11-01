/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:18:17 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 01:12:54 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "stdlib.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (!(alloc = malloc(count * size)))
		return (NULL);
	ft_bzero(alloc, count * size);
	return (alloc);
}
