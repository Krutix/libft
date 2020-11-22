/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:57:33 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 22:31:56 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

#include "ftdef.h"

typedef struct		s_list
{
	struct s_list	*next;
	t_data			data;
}					t_list;

t_list	*ft_create_elem(t_data data);
void	ft_list_push_front(t_list **begin_list, t_data data);

#endif
