/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:42:01 by fdiego            #+#    #+#             */
/*   Updated: 2020/09/29 16:43:33 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

typedef struct	s_vector {
	unsigned int	size;
	unsigned int	reserv;
	unsigned int	*array;
}				t_vector;

void			ft_vec_constructor(t_vector **vec);
void			ft_vec_realloc(t_vector *vec, unsigned int new_reserv);
void			ft_vec_destructor(t_vector *vec);
void			ft_vec_push_back(t_vector *vec, int nbr);
void			*return_clean_vec(t_vector *vec);

#endif
