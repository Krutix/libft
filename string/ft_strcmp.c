/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:11:59 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/07 23:09:27 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strcmp_s(char const *s1, char const *s2)
{
	if (s1 == NULL || s2 == NULL)
		return ((!s1 * -1) + (!s2 * 1));
	return (ft_strcmp(s1, s2));
}

int	ft_strcmp(char const *s1, char const *s2)
{
	while (*s1 || *s2)
		if (*s1++ != *s2++)
			return (*(s1 - 1) - *(s2 - 1));
	return (0);
}
