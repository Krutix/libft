/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:42:01 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 18:23:55 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

#include <stddef.h>
#include "../../../include/ftdef.h"

typedef struct	s_vector {
	unsigned int	size;
	unsigned int	reserv;
	void			**array;
}				t_vector;

extern void			ft_vec_create(t_vector **vec);
extern t_bool		ft_vec_realloc(t_vector *vec, size_t new_reserv);
extern void			ft_vec_destructor(t_vector *vec, void (*del)(void*));
extern void			*ft_vec_returndel(t_vector *vec, void (*del)(void *));
extern t_bool		ft_vec_push_back(t_vector *vec, void *data);
extern void			*ft_vec_pop_back(t_vector *vec);
extern void			**ft_vec_fetch_array(t_vector *vec, size_t *out_size);

#endif
