/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:16:56 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:40:56 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static int	array_size(char const *str, char *charset)
{
	int		offset;
	int		words_inside;

	offset = 0;
	words_inside = 0;
	while (str[offset])
	{
		if (!ft_strchr(charset, str[offset]))
		{
			while (str[offset] && !ft_strchr(charset, str[offset]))
				offset++;
			words_inside++;
		}
		else
			offset++;
	}
	return (words_inside);
}

static void	*free_array_nt(void **array)
{
	int i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (NULL);
}
#include <stdio.h>
char		**ft_split(char const *str, char *charset)
{
	int			word_counter;
	char const	*word_start;
	char		**arr;

	word_counter = 0;
	if (!(arr = malloc((array_size(str, charset) + 1) * sizeof(char*))))
		return (NULL);
	while (*str)
	{
		if (!ft_strchr(charset, *str))
		{
			word_start = str++;
			while (*str && !ft_strchr(charset, *str))
				str++;
			if (!(arr[word_counter++] = ft_substr(word_start, 0, str - word_start)))
				return (char **)free_array_nt((void**)arr);
		}
		else
			str++;
	}
	arr[word_counter] = NULL;
	return (arr);
}
