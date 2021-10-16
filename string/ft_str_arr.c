/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:31:28 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:31:34 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "stdlib.h"

void	ft_strarr_clear(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

size_t	ft_strarr_size(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
