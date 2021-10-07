/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:17:10 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/07 23:10:18 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <sys/types.h>
# include "ftdef.h"

extern int		ft_putchar_fd(char ch, int fd);
extern ssize_t	ft_putendl_s(const char *s);
extern ssize_t	ft_putendl(const char *s);
extern int		ft_putendl_fd_s(char const *s, int fd);
extern int		ft_putendl_fd(char const *s, int fd);
extern int		ft_putnbr_base_fd(t_llint nb, char *base, int fd);
extern int		ft_putnbr_fd(t_llint nb, int fd);
extern int		ft_putstr_fd_s(char const *s, int fd);
extern int		ft_putstr_fd(char const *s, int fd);
extern ssize_t	ft_putstr_s(const char *s);
extern ssize_t	ft_putstr(const char *s);
extern ssize_t	ft_putmultistr(char *const mutlistring[]);
extern ssize_t	ft_putmultistr_delim(char *const mutlistring[],
					const char *delimiter);
extern void		ft_print_memory(void const *addr, size_t size);
extern int		ft_get_next_line(int fd, char **ln);
extern int		ft_read_next_line(int fd, char **line);
extern int		ft_read_next(int fd, char **line, char next);

#endif
