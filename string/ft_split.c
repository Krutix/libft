/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 12:53:42 by fdiego            #+#    #+#             */
/*   Updated: 2020/10/31 00:03:12 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_sep(char str, char *charset)
{
	int offset;

	offset = 0;
	while (charset[offset])
		if (str == charset[offset++])
			return (1);
	return (0);
}

static int	array_size(char *str, char *charset)
{
	int		offset;
	int		words_inside;

	offset = 0;
	words_inside = 0;
	while (str[offset])
	{
		if (!is_sep(str[offset], charset))
		{
			while (str[offset] && !is_sep(str[offset], charset))
				offset++;
			words_inside++;
		}
		else
			offset++;
	}
	return (words_inside);
}

static char	*strdup_to_charset(char *src, char *charset, int *offset)
{
	unsigned int	len;
	char			*copy;

	len = 0;
	while (src[(*offset) + len] && !is_sep(src[(*offset) + len], charset))
		len++;
	copy = malloc((len + 1) * sizeof(char));
	len = 0;
	while (src[*offset] && !is_sep(src[*offset], charset))
	{
		copy[len] = src[*offset];
		len++;
		(*offset)++;
	}
	copy[len] = '\0';
	return (copy);
}

char		**ft_split(char *str, char *charset)
{
	int		offset;
	int		word_counter;
	char	**arr;

	offset = 0;
	word_counter = 0;
	arr = malloc((array_size(str, charset) + 1) * sizeof(char*));
	while (str[offset])
	{
		if (!is_sep(str[offset], charset))
		{
			arr[word_counter] = strdup_to_charset(str, charset, &offset);
			word_counter++;
		}
		else
			offset++;
	}
	arr[word_counter] = NULL;
	return (arr);
}
