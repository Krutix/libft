/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_next_line_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:27:38 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:27:39 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read_next_line.h"
#include "ft_list.h"

int	fd_list_cmp(t_rnl_buffer *rnl_buffer, int *fd)
{
	if (rnl_buffer->fd == *fd)
		return (0);
	return (-1);
}

int	ft_rnl_error(char **free_str, \
		int fd, t_list **begin_list)
{
	if (free_str)
	{
		free(*free_str);
		*free_str = NULL;
	}
	ft_list_remove_if(begin_list, &fd, &fd_list_cmp, NULL);
	return (-1);
}
