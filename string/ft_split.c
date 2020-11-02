/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 12:53:42 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 18:29:31 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../collection/vector/include/ft_vector.h"

static int	is_sep(char ch, char *charset)
{
	while (*charset)
		if (ch == *charset++)
			return (1);
	return (0);
}

static char	*strdup_to_charset(char **src, char *charset)
{
	unsigned int	len;
	char			*copy;

	len = 0;
	while ((*src)[len] && !is_sep((*src)[len], charset))
		len++;
	copy = malloc((len + 1) * sizeof(char));
	len = 0;
	while (**src && !is_sep(**src, charset))
		copy[len++] = *(*src)++;
	copy[len] = '\0';
	return (copy);
}

char		**ft_split(char *str, char *charset)
{
	t_vector	*vec;
	char		**array;

	ft_vec_create(&vec);
	if (!vec)
		return (NULL);
	while (str)
		if (!is_sep(*str, charset))
		{
			if (!ft_vec_push_back(vec, strdup_to_charset(&str, charset)))
				return (ft_vec_returndel(vec, &free));
		}
		else
			str++;
	ft_vec_push_back(vec, NULL);
	array = (char**)ft_vec_fetch_array(vec, NULL);
	ft_vec_destructor(vec, NULL);
	return (array);
}
