#ifndef FT_IO_H
#define FT_IO_H

#include "ftdef.h"

extern int		ft_putchar_fd(char ch, int fd);
extern int		ft_putendl_fd(char *s, int fd);
extern int		ft_putnbr_base_fd(llint nb, char *base, int fd);
extern int		ft_putnbr_fd(llint nb, int fd);
extern int		ft_putstr_fd(char *s, int fd);
extern int		ft_printf(char *format, ...);
extern int		ft_print_memory(void *addr, size_t size);

#endif