/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_next_line.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:26:01 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/30 09:21:27 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_NEXT_LINE_H
# define READ_NEXT_LINE_H

# include <stdlib.h>
# include "ftdef.h"
# include "ft_list.h"

# ifndef RNL_BUFFER_SIZE
#  define RNL_BUFFER_SIZE 1024
# endif

typedef struct s_rnl_buffer
{
	int				fd;
	int				size;
	int				start_pos;
	char			str[RNL_BUFFER_SIZE];
}					t_rnl_buffer;

int	fd_list_cmp(t_rnl_buffer *rnl_buffer, int *fd);
int	ft_rnl_error(char **free_str, int fd, t_list **begin_list);

#endif
