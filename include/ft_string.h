/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:34:23 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/30 08:47:48 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "ftdef.h"

extern t_llint	ft_atoi_base(char *str, char *base);
extern t_llint	ft_atoi(const char *str);

extern size_t	ft_utob(char *buffer, t_ullint num);
extern size_t	ft_utob_16(char *buffer, t_ullint num, char *base);
extern size_t	ft_utob_2(char *buffer, t_ullint num);
extern size_t	ft_utob_n(char *buffer, t_ullint num, char *base);
extern char		*ft_utob_bt(char *buffer_end, t_ullint num);
extern char		*ft_utob_bt_n(char *buffer_end, t_ullint num, char *base);
extern char		*ft_utob_bt_16(char *buffer_end, t_ullint num, char *base);
extern char		*ft_utob_bt_2(char *buffer_end, t_ullint num);

extern char		*ft_itoa(t_llint num);

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
extern char		*ft_memjoin(void const *s1, void const *s2, \
							size_t len1, size_t len2);

extern int		ft_wstrtostr(wchar_t *str, char *buffer);
extern int		ft_wchtoch(wchar_t ch, char *buffer);

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

extern int		ft_strcmp(char const *s1, char const *s2);
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

extern char		*ft_strdup(char const *src);
extern char		*ft_substr(char const *src, unsigned int start, size_t len);
extern char		*ft_strtrim(char const *str, char const *set);
extern char		**ft_split(char const *str, char *charset);
extern char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
extern void		ft_sort_str_tab(char **tab, int (*cmp)(char *, char *));

extern t_uint	ft_ulen(t_ullint num);
extern t_uint	ft_ulen_n(t_ullint num, t_uint base);
extern t_uint	ft_ulen_2(t_ullint num);
extern t_uint	ft_ulen_16(t_ullint num);

#endif
