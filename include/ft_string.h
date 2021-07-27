#ifndef FT_STRING_H
# define FT_STRING_H

# include "ftdef.h"

extern t_llint		ft_atoi_base(char *str, char *base);
extern t_llint		ft_atoi(const char *str);
extern t_bool		ft_strtol_m(const char *str, t_ullint max_abs, int64_t *r);
extern t_bool		ft_strtoi_m(const char *str, t_ullint max_abs, int32_t *r);

/*!
 * \fn char *ft_utob(char *buffer, t_ullint num);
 * \brief convert num to string
 * \see ft_utob_n() ft_utob_16() ft_utob_2()
 * \param buffer a pointer to memery area start
 * \param num number to convert
 * \return size of a string
 */
extern size_t		ft_utob(char *buffer, t_ullint num);
/*!
 * \fn size_t ft_utob_16(char *buffer, t_ullint num, char *base);
 * \brief convert num to string
 * \see ft_utob()
 * \param buffer a pointer to memery area start
 * \param num number to convert
 * \param base hex base to convert
 * \warning behavior is underfined if len of base is less then 16
 * \return size of a string
 */
extern size_t		ft_utob_16(char *buffer, t_ullint num, char *base);
/*!
 * \fn size_t ft_utob_n(char *buffer, t_ullint num, char *base);
 * \brief convert num to string in bin base
 * \see ft_utob()
 * \param buffer a pointer to memery area start
 * \param num number to convert
 * \return size of a string
 */
extern size_t		ft_utob_2(char *buffer, t_ullint num);
/*!
 * \fn size_t ft_utob_n(char *buffer, t_ullint num, char *base);
 * \brief convert num to string in castom base
 * \see ft_utob()
 * \param buffer a pointer to memery area start
 * \param num number to convert
 * \param base base to convert
 * \return size of a string
 */
extern size_t		ft_utob_n(char *buffer, t_ullint num, char *base);
/*!
 * \fn char *ft_utob_bt(char *buffer_end, t_ullint num);
 * \brief convert num to string, buffer backward filling
 * \see ft_utob_bt_n() ft_utob_bt_16() ft_utob_bt_2()
 * \deprecated
 * \param buffer_end a pointer to memery area end
 * \param num number to convert
 * \return a pointer to the start of number string
 */
extern char			*ft_utob_bt(char *buffer_end, t_ullint num);
/*!
 * \fn char *ft_utob_bt_n(char *buffer_end, t_ullint num, char *base);
 * \brief convert num to string, buffer backward filling in castom base
 * \see ft_utob_bt() 
 * \deprecated
 * \param buffer_end a pointer to memery area end
 * \param num number to convert
 * \param base base to convert
 * \return a pointer to the start of number string
 */
extern char			*ft_utob_bt_n(char *buffer_end, t_ullint num, char *base);
/*!
 * \fn char *ft_utob_bt_n(char *buffer_end, t_ullint num, char *base);
 * \brief convert num to string, buffer backward filling in hex base
 * \see ft_utob_bt() 
 * \deprecated
 * \param buffer_end a pointer to memery area end
 * \param num number to convert
 * \param base hex base to convert
 * \warning behavior is underfined if len of base is less then 16
 * \return a pointer to the start of number string
 */
extern char			*ft_utob_bt_16(char *buffer_end, t_ullint num, char *base);
/*!
 * \fn char *ft_utob_bt_2(char *buffer_end, t_ullint num);
 * \brief convert num to string, buffer backward filling in bin base
 * \see ft_utob_bt() 
 * \deprecated
 * \param buffer_end a pointer to memery area end
 * \param num number to convert
 * \return a pointer to the start of number string
 */
extern char			*ft_utob_bt_2(char *buffer_end, t_ullint num);

extern char			*ft_itoa(t_llint num);

extern t_bool		ft_isdigit(int c);
extern t_bool		ft_isalpha(int c);
extern t_bool		ft_isalnum(int c);
extern t_bool		ft_isascii(int c);
extern t_bool		ft_isprint(int c);
extern t_bool		ft_isspace(int c);
extern int			ft_tolower(int c);
extern int			ft_toupper(int c);

/*!
 * \fn void *ft_memset(void *mem, int value, size_t size)
 * \brief fill memory with a constant byte
 * \param mem memery address start
 * \param value value used to set on memory. interpreted as unsigned char
 * \param size the number of bytes to fill
 * \return a pointer to the memory area mem
 */
extern void			*ft_memset(void *mem, int value, size_t size);

/*!
 * \fn void ft_bzero(void *mem, size_t size);
 * \brief fill memory with a zero byte
 * \param mem memery address start
 * \param size the number of bytes to fill
 */
extern void			ft_bzero(void *mem, size_t size);

/*!
 * \fn void *ft_calloc(size_t count, size_t size)
 * \brief allocate memory and fill it with a zero bytes
 * \param count number of elements to allocate
 * \param size size of one element
 * \return a pointer to the allocated memory area
 * \warning return NULL if allocation failes
 */
extern void			*ft_calloc(size_t count, size_t size);

/*!
 * \fn void *ft_memcpy(void *dest, const void *src, size_t n)
 * \see ft_memmove() ft_memccpy()
 * \brief copies n bytes from memory area src to dest 
 * \param dest memory area to copy to
 * \param src memory area from which to copy
 * \param n number of bytes to copy
 * \return a pointer to the memory area dest
 * \warning the memory areas must not overlap. use ft_memmove() if memory areas do overlap
 */
extern void			*ft_memcpy(void *dest, const void *src, size_t n);

/*!
 * \fn void *ft_memccpy(void *dest, const void *src, int c, size_t n)
 * \brief copies n bytes from memory area src to dest or stoped after find in srcs c character
 * \see ft_memmove() ft_memcpy()
 * \param dest memory area to copy to
 * \param src memory area from which to copy
 * \param c stop symbol. interpreted as unsigned char
 * \param n number of bytes to copy
 * \return a pointer to the memory area dest
 * \warning the memory areas must not overlap
 */
extern void			*ft_memccpy(void *dest, const void *src, int c, size_t n);

/*!
 * \fn void *ft_memmove(void *dest, const void *src, size_t n)
 * \see ft_memcpy()
 * \brief copies n bytes from memory area src to dest 
 * \param dest memory area to copy to
 * \param src memory area from which to copy
 * \param n number of bytes to copy
 * \return a pointer to the memory area dest
 */
extern void			*ft_memmove(void *dest, const void *src, size_t n);

/*!
 * \fn void *ft_memchr(const void *s, int c, size_t n)
 * \see ft_strchr() ft_strrchr()
 * \brief scans the initial n bytes of the memory area pointed to by s for the first instance of c
 * \param s memory area to scan
 * \param c character to find. interpreted as unsigned char
 * \param n number of bytes to scan
 * \return a pointer to the matching byte or NULL if the character does not occur in the given memory area
 */
extern void			*ft_memchr(const void *s, int c, size_t n);

/*!
 * \fn int ft_memcmp(const void *s1, const void *s2, size_t n)
 * \see ft_strcmp() ft_strncmp()
 * \brief compares the first n bytes of the memory areas s1 and s2
 * \param n number of bytes to scan
 * \return <0 if s1 is less then s2, >0 if s2 is less then s1 and 0 if memory areas is equal
 */
extern int			ft_memcmp(const void *s1, const void *s2, size_t n);

/*!
 * \fn void *ft_memjoin(void const *s1, void const *s2, size_t len1, size_t len2)
 * \see ft_strjoin()
 * \brief concatenates s1 with len1 and s2 with len2 to allocated memory area
 * \return result of cancateneted string
 * \warning return NULL if allocation failes
 */
extern void			*ft_memjoin(void const *s1, void const *s2, \
							size_t len1, size_t len2);

/*!
 * \fn int ft_wstrtostr(wchar_t *str, char *buffer);
 * \see ft_wstrtostr()
 * \brief convert 32bite wchar string to 8bite char string
 * \param str 32bite wchar string
 * \param buffer output 8bite char string
 * \return number of 8bites characters converted from 32bite wchar
 * \throw return -1 if wchar is invalid
 */
extern int			ft_wstrtostr(wchar_t *str, char *buffer);

/*!
 * \fn int ft_wchtoch(wchar_t ch, char *buffer);
 * \see ft_wstrtostr()
 * \brief convert 32bite wchar to 8bite char string
 * \param ch 32bite wchar
 * \param buffer output 8bite char string
 * \return number of 8bites characters converted from 32bite wchar
 * \throw return -1 if wchar is invalid
 */
extern int			ft_wchtoch(wchar_t ch, char *buffer);

/*!
 * \fn size_t	ft_strlen(const char *s);
 * \see ft_strnlen()
 * \brief calculates the length of the string
 * \return length of the string
 */
extern size_t		ft_strlen(const char *s);
/*!
 * \fn size_t	ft_strnlen(const char *str, size_t n);
 * \see ft_strnlen()
 * \brief calculates the length of the string with first n symbols
 * \return length of the string or n if len of string is greater then length of str
 */
extern size_t		ft_strnlen(const char *str, size_t n);

extern char			*ft_strcpy(char *dest, char const *src);
extern char			*ft_strncpy(char *dest, char const *src, unsigned int n);
extern char			*ft_strcat(char *dest, char const *src);
extern char			*ft_strncat(char *dest, char const *src, unsigned int n);
extern size_t		ft_strlcpy(char *dest, char const *src, size_t size);
extern size_t		ft_strlcat(char *dest, char const *src, size_t size);

extern int			ft_strcmp(char const *s1, char const *s2);
extern int			ft_strncmp(const char *s1, const char *s2, size_t n);
extern char const	*ft_strstr(char const *str, char const *to_find);
extern char const	*ft_strnstr(char const *str, char const *to_find, size_t size);
extern char			*ft_strrchr(const char *s, int c);
extern char			*ft_strchr(const char *s, int c);

extern char			*ft_strdup(char const *src);
extern char			*ft_substr(char const *src, unsigned int start, size_t len);
extern char			*ft_strtrim(char const *str, char const *set);
extern char			**ft_split(char const *str, char *charset);
extern char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
extern void			ft_sort_str_tab(char **tab, int (*cmp)(char *, char *));

extern t_uint		ft_ulen(t_ullint num);
extern t_uint		ft_ulen_n(t_ullint num, t_uint base);
extern t_uint		ft_ulen_2(t_ullint num);
extern t_uint		ft_ulen_16(t_ullint num);

extern void			ft_strarr_clear(char **s);
extern size_t		ft_strarr_size(char **s);

#endif
