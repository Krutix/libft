#ifndef FT_STRING_H
# define FT_STRING_H

#include "ftdef.h"

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

extern size_t	ft_strlen(const char *s);
extern size_t	ft_strcount_if(const char *str, t_bool (*counter)(const char *));
extern char		*ft_strcpy(char *dest, char *src);
extern char		*ft_strncpy(char *dest, char *src, unsigned int n);
extern size_t	ft_strlcpy(char *dest, const char *src, size_t size);
extern char		*ft_strcat(char *dest, char *src);
extern char		*ft_strncat(char *dest, char *src, unsigned int n);
extern size_t	ft_strlcat(char *dest, const char *src, size_t size);

extern int		ft_strcmp(char *s1, char *s2);
extern int		ft_strncmp(const char *s1, const char *s2, size_t n);
extern char		*ft_strstr(char *str, char *to_find);
extern char		*ft_strnstr(char *str, char *to_find, size_t size);
extern char		*ft_strrchr(const char *s, int c);
extern char		*ft_strchr(const char *s, int c);

extern char		*ft_strdup(char *src);
extern char		*ft_substr(char const *src, unsigned int start, size_t len);
extern char		*ft_strtrim(char const *str, char const *set);
extern char		**ft_split(char *str, char *charset);
extern void		ft_sort_str_tab(char **tab, int (*cmp)(char *, char *));
extern char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif