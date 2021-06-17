#ifndef FT_IO_H
# define FT_IO_H

# include "ftdef.h"

extern int		ft_putchar_fd(char ch, int fd);
extern int		ft_putendl_fd(char *s, int fd);
extern int		ft_putnbr_base_fd(t_llint nb, char *base, int fd);
extern int		ft_putnbr_fd(t_llint nb, int fd);
extern int		ft_putstr_fd(char *s, int fd);
extern void		ft_print_memory(void *addr, size_t size);
extern int		ft_read_next_line(int fd, char **line);
extern int		ft_read_next(int fd, char **line, char next);

#endif
