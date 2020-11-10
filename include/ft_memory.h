#ifndef FT_MEMORY_H
# define FT_MEMORY_H

#include <stddef.h>

extern void	*ft_memset(void *mem, int value, size_t size);
extern void	ft_bzero(void *mem, size_t size);
extern void	*ft_calloc(size_t count, size_t size);
extern void	*ft_memcpy(void *dest, const void *src, size_t n);
extern void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
extern void	*ft_memmove(void *dest, const void *src, size_t n);
extern void	*ft_memchr(const void *s, int c, size_t n);
extern int	ft_memcmp(const void *s1, const void *s2, size_t n);

#endif