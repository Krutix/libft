/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:36:01 by fdiego            #+#    #+#             */
/*   Updated: 2021/01/28 17:36:04 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "ftdef.h"

typedef struct {
    int     x;
    int     y;
}           t_v2i;

typedef struct {
    float   x;
    float   y;
}           t_v2f;

float       ft_v2f_mag(t_v2f vec);
t_v2f       ft_v2f_norm(t_v2f vec);
t_v2f       ft_v2f_fnorm(t_v2f vec);

t_ullint	ft_abs(t_llint num);
float	    ft_absf(float num);
t_bool		ft_is_prime(t_ullint num);
t_llint		ft_pow(t_llint num, size_t pow);
t_ullint	ft_sqrt(t_ullint nb);

void		ft_swap_n(void *v1, void *v2, size_t size);
void		ft_swap_8(int64_t *v1, int64_t *v2);
void		ft_swap_4(int32_t *v1, int32_t *v2);
void		ft_swap_2(int16_t *v1, int16_t *v2);
void		ft_swap_1(int8_t *v1, int8_t *v2);

t_llint		ft_maxi(t_llint a1, t_llint a2);
t_llint		ft_mini(t_llint a1, t_llint a2);
t_ullint	ft_maxu(t_ullint a1, t_ullint a2);
t_ullint	ft_minu(t_ullint a1, t_ullint a2);
double	    ft_maxd(double a1, double a2);
double	    ft_mind(double a1, double a2);
float		ft_maxf(float a1, float a2);
float		ft_minf(float a1, float a2);

union t_double_unpack
{
    double      f;
    uint64_t    i;
};

union t_float_unpack
{
    float       f;
    uint32_t    i;
};

#endif
