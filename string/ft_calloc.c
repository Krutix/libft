/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 23:18:17 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:37:56 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (!(alloc = malloc(count * size)))
		return (NULL);
	ft_bzero(alloc, count * size);
	return (alloc);
}
