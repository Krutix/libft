/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:34:23 by fdiego            #+#    #+#             */
/*   Updated: 2021/01/28 17:35:53 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "ftdef.h"

extern int		ft_atoi_base(char *str, char *base);
extern int		ft_atoi(const char *str);
extern char		*ft_itoa(int num);

extern t_bool	ft_isdigit(int c);
extern t_bool	ft_isalpha(int c);
extern t_bool	ft_isalnum(int c);
extern t_bool	ft_isascii(int c);
extern t_bool	ft_isprint(int c);
extern t_bool	ft_isspace(int c);
extern int		ft_tolower(int c);
extern int		ft_toupper(int c);

extern void		*ft_memset(void *mem, int value, size_t size);
extern void		ft_bzero(void *mem, size_t size);
extern void		*ft_calloc(size_t count, size_t size);
extern void		*ft_memcpy(void *dest, const void *src, size_t n);
extern void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
extern void		*ft_memmove(void *dest, const void *src, size_t n);
extern void		*ft_memchr(const void *s, int c, size_t n);
extern int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
****************************************************
**
**		PROCESSES ONLY WITH VALID STRING
**
** 	strlen		|	return length of string
**  strnlen		|	return length <= n
**
****************************************************
*/

extern size_t	ft_strlen(const char *s);
extern size_t	ft_strnlen(const char *str, size_t n);

/*
****************************************************
**
**	strcpy		|	copy string to null terminant
**	strncpy		|	copy string to null terminant
**				-		max 'n' characters
**				-	not guarantees null terminated string
**	strlcpy		|	copy string in 'dest'
**				-		with 'size' the 'dest' size
**
****************************************************
**
**	strcat		|	cat 'src' to 'dest'
**	strncat		|	cat 'src' to 'dest'
**				-		max 'n' characters
**				-	not guarantees null terminated string
**	strlcat		|	cat 'src' to 'dest'
**				-		with 'size' the 'dest' size
**
****************************************************
*/

extern char		*ft_strcpy(char *dest, char *src);
extern char		*ft_strncpy(char *dest, char *src, unsigned int n);
extern char		*ft_strcat(char *dest, char *src);
extern char		*ft_strncat(char *dest, char *src, unsigned int n);
extern size_t	ft_strlcpy(char *dest, const char *src, size_t size);
extern size_t	ft_strlcat(char *dest, const char *src, size_t size);

extern int		ft_strcmp(char *s1, char *s2);
extern int		ft_strncmp(const char *s1, const char *s2, size_t n);
extern char		*ft_strstr(char *str, char *to_find);
extern char		*ft_strnstr(char *str, char *to_find, size_t size);
extern char		*ft_strrchr(const char *s, int c);
extern char		*ft_strchr(const char *s, int c);

/*
****************************************************
**
**		PROCESSES ONLY WITH VALID STRING
**
** 	strdup		|	dublicate src string
** 	substr		|	create substr from src
**				--		from start with 'len' size
**				--	when start >= strlen(src)
**				--		begavior is undefined
**	strtrim		|	trimed characters from start
**				--		and end of string
**	split		|	covert string to string tab
**				--		divided by any character
**				--		from charset
**	strmapi		|	copy string coverting all
**				--		characters by f
**
**	all			|	return NULL when alloc fails
**
****************************************************
*/

extern char		*ft_strdup(char *src);
extern char		*ft_substr(char const *src, unsigned int start, size_t len);
extern char		*ft_strtrim(char const *str, char const *set);
extern char		**ft_split(char const *str, char *charset);
extern char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
extern void		ft_sort_str_tab(char **tab, int (*cmp)(char *, char *));

#endif
