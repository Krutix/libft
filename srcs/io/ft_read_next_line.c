/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:36:27 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/30 08:26:31 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_string.h"
#include "ft_read_next_line.h"
#include "ft_list.h"
#include "stdio.h"

static t_bool	ft_rnl_append_to(t_rnl_buffer *src, \
					char **line, size_t *line_size)
{
	size_t	i;
	t_bool	reach_ch;
	char	*t;

	i = src->start_pos;
	while (i < (size_t)src->size && src->str[i] != '\n')
		i++;
	reach_ch = (i != (size_t)src->size);
	t = *line;
	*line = ft_memjoin(*line, &src->str[src->start_pos], \
						*line_size, i - src->start_pos);
	*line_size += i - src->start_pos;
	free(t);
	if (reach_ch)
		src->start_pos = i + 1;
	else
		src->start_pos = 0;
	return (reach_ch);
}

static t_list	*__find_buffer(int fd, t_list **buffer_list, t_list **fd_node)
{
	*fd_node = NULL;
	if (*buffer_list)
		*fd_node = ft_list_find(*buffer_list, &fd, &fd_list_cmp);
	if (!*fd_node)
	{
		*fd_node = ft_create_list_i(sizeof(t_rnl_buffer));
		if (!ft_list_push_front(buffer_list, *fd_node))
			return (NULL);
		((t_rnl_buffer *)(*fd_node)->data)->fd = fd;
	}
	return (*fd_node);
}

static int	__read(int fd, char *buffer, int *buffer_size)
{
	*buffer_size = read(fd, buffer, RNL_BUFFER_SIZE);
	return (*buffer_size);
}

int	ft_read_next_line(int fd, char **line)
{
	static t_list	*buffer_list;
	t_list			*fd_node;
	size_t			line_size;
	t_rnl_buffer	*buffer;

	if (!__find_buffer(fd, &buffer_list, &fd_node))
		return (-1);
	buffer = fd_node->data;
	*line = NULL;
	line_size = 0;
	while (buffer->start_pos || __read(fd, &buffer->str[0], &buffer->size) > 0)
	{
		if (ft_rnl_append_to(buffer, line, &line_size))
			return (line_size + 1);
		if (!*line)
			return (ft_rnl_error(line, fd, &buffer_list));
	}
	if (buffer->size == 0)
	{
		ft_list_remove_if(&buffer_list, &fd, &fd_list_cmp, NULL);
		if (*line)
			return (line_size + 1);
		return (0);
	}
	return (ft_rnl_error(line, fd, &buffer_list));
}
