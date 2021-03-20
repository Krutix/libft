/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:36:27 by fdiego            #+#    #+#             */
/*   Updated: 2021/01/08 21:47:38 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_string.h"
#include "ft_read_next_line.h"
#include "ft_list.h"

static char		*ft_memjoin(void const *s1, void const *s2,
							size_t len1, size_t len2)
{
	char	*join_str;

	join_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!join_str)
		return (NULL);
	ft_memcpy(join_str, s1, len1);
	ft_memcpy(join_str + len1, s2, len2);
	join_str[len1 + len2] = '\0';
	return (join_str);
}

static t_bool	ft_rnl_append_to(t_rnl_buffer *src, char **line,
						size_t *line_size)
{
	size_t	i;
	t_bool	reach_ch;
	char	*t;

	i = src->start_pos;
	while (i < (size_t)src->size && src->str[i] != '\n')
		i++;
	reach_ch = (i != (size_t)src->size);
	t = *line;
	*line = ft_memjoin(*line, &src->str[src->start_pos],
						*line_size, i - src->start_pos);
	*line_size += i - src->start_pos;
	free(t);
	if (reach_ch)
		src->start_pos = i + 1;
	else
		src->start_pos = 0;
	return (reach_ch);
}

static int		fd_list_cmp(t_rnl_buffer *rnl_buffer, int *fd)
{
	if (rnl_buffer->fd == *fd)
		return (0);
	return (-1);
}

static int		ft_rnl_error(char **free_str,
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

int				ft_read_next_line(int fd, char **line)
{
	static t_list	*buffer_list;
	size_t			line_size;
	t_list			*fd_node = NULL;
	t_rnl_buffer	*buffer;

	if (buffer_list)
		fd_node = ft_list_find(buffer_list, &fd, &fd_list_cmp);
	if (!fd_node)
	{
		if (!ft_list_push_front(&buffer_list,
				fd_node = ft_create_list_i(sizeof(t_rnl_buffer))))
			return (-1);
		ft_bzero(fd_node->data, sizeof(t_rnl_buffer));
		((t_rnl_buffer*)fd_node->data)->fd = fd;
	}
	*line = NULL;
	buffer = fd_node->data; 
	line_size = 0;
	while (buffer->start_pos ||
		(buffer->size = read(fd, &buffer->str[0], RNL_BUFFER_SIZE)) > 0)
	{
		if (ft_rnl_append_to(buffer, line, &line_size))
			return (line_size+1);
		if (!*line)
			return (ft_rnl_error(line, fd, &buffer_list));
	}
	if (buffer->size == 0)
	{
		ft_list_remove_if(&buffer_list, &fd, &fd_list_cmp, NULL);
		return (*line ? line_size + 1 : 0);
	}
	return (ft_rnl_error(line, fd, &buffer_list));
}
