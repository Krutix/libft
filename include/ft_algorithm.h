/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:19:10 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/09 06:57:30 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGORITHM_H
# define FT_ALGORITHM_H

# include "ftdef.h"

extern t_ft_err	ft_qsort(void *begin, void *end, \
				size_t size_of_cell, t_bool (*lower)());

extern void		ft_swap_n(void *v1, void *v2, size_t size);
extern void		ft_swap_8(int64_t *v1, int64_t *v2);
extern void		ft_swap_4(int32_t *v1, int32_t *v2);
extern void		ft_swap_2(int16_t *v1, int16_t *v2);
extern void		ft_swap_1(int8_t *v1, int8_t *v2);

#endif
