/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:42:01 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/23 05:52:31 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

#include <stddef.h>
#include "ftdef.h"

typedef struct	s_vector {
	unsigned int	size;
	unsigned int	reserv;
	t_data			*array;
}				t_vector;

extern t_vector		*ft_vec_create(void);
extern t_vector		*ft_vec_create_reserv(size_t reserv);
extern t_bool		ft_vec_realloc(t_vector *vec, size_t new_reserv);
extern void			ft_vec_destructor(t_vector *vec, void (*del)(t_data));
extern void			*ft_vec_returndel(t_vector *vec, void (*del)(t_data));
extern t_bool		ft_vec_push_back(t_vector *vec, t_data data);
extern t_data		ft_vec_pop_back(t_vector *vec);
extern t_data		*ft_vec_fetch_array(t_vector *vec, size_t *out_size);

#endif
