/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:42:01 by fdiego            #+#    #+#             */
/*   Updated: 2021/01/28 17:22:06 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "ftdef.h"

typedef struct		s_vector {
	size_t	size;
	size_t	reserv;
	t_uint	cell_size;
	void *	array;
}					t_vector;

extern t_bool		ft_vec_realloc(t_vector *vec, size_t new_reserv);

extern t_vector		*ft_vec_create(t_uint cell_size);
extern void			ft_vec_construct(t_vector *vec, t_uint cell_size);
extern void			ft_vec_destructor(t_vector *vec);

extern void			ft_vec_pop_back(t_vector *vec);

extern t_bool		ft_vec_push_reserv(t_vector *vec);
extern t_bool		ft_vec_push_back(t_vector *vec, void *data);

extern void			ft_vec_remove_at(t_vector *vec, size_t pos, void (*del)(void*));
extern void			*ft_vec_at(t_vector *vec, size_t pos);
extern void			*ft_vec_top(t_vector *vec);
extern void			*ft_vec_back(t_vector *vec);

extern void			*ft_vec_fetch_array(t_vector *vec, size_t *out_size);

#endif
