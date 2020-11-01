#ifndef FT_IO_H
#define FT_IO_H

extern void		ft_putchar_fd(char ch, int fd);
extern void		ft_putendl_fd(char *s, int fd);
extern void		ft_putnbr_base_fd(int nb, char *base, int fd);
extern void		ft_putnbr_fd(int nb, int fd);
extern void		ft_putstr_fd(char *s, int fd);

#endif