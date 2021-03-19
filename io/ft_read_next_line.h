/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:26:01 by fdiego            #+#    #+#             */
/*   Updated: 2021/01/22 09:05:49 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_NEXT_LINE_H
# define READ_NEXT_LINE_H

# include <stdlib.h>
# include "ftdef.h"

# ifndef RNL_BUFFER_SIZE
#  define RNL_BUFFER_SIZE 1024
# endif

typedef struct		s_rnl_buffer
{
	int				fd;
	int				size;
	int				start_pos;
	char			str[RNL_BUFFER_SIZE];
}					t_rnl_buffer;

#endif
