/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:42:01 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/01 19:28:55 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

typedef struct	s_vector {
	unsigned int	size;
	unsigned int	reserv;
	void			**array;
}				t_vector;

void			ft_vec_create(t_vector **vec);
void			ft_vec_realloc(t_vector *vec, size_t new_reserv);
void			ft_vec_destructor(t_vector *vec, void (*del)(void*));
void			ft_vec_push_back(t_vector *vec, void *data);
void			*ft_vec_pop_back(t_vector *vec);

#endif
