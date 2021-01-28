/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:25:41 by fdiego            #+#    #+#             */
/*   Updated: 2021/01/28 17:35:47 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include "ftdef.h"

extern int		ft_putchar_fd(char ch, int fd);
extern int		ft_putendl_fd(char *s, int fd);
extern int		ft_putnbr_base_fd(t_llint nb, char *base, int fd);
extern int		ft_putnbr_fd(t_llint nb, int fd);
extern int		ft_putstr_fd(char *s, int fd);
extern int		ft_printf(char *format, ...);
extern void		ft_print_memory(void *addr, size_t size);

#endif
