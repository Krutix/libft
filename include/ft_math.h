/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:36:01 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/30 08:55:58 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "ftdef.h"

typedef struct s_v2i {
	int		x;
	int		y;
}			t_v2i;

typedef struct s_v2f {
	float	x;
	float	y;
}			t_v2f;

extern float		ft_v2f_mag(t_v2f vec);
extern float		ft_v2f_sqmag(t_v2f vec);
extern t_v2f		ft_v2f_norm(t_v2f vec);
extern t_v2f		ft_v2f_fnorm(t_v2f vec);

extern t_ullint		ft_abs(t_llint num);
extern float		ft_absf(float num);
extern t_bool		ft_is_prime(t_ullint num);
extern t_llint		ft_pow(t_llint num, size_t pow);
extern t_ullint		ft_sqrt(t_ullint nb);

extern t_llint		ft_maxi(t_llint a1, t_llint a2);
extern t_llint		ft_mini(t_llint a1, t_llint a2);
extern t_ullint		ft_maxu(t_ullint a1, t_ullint a2);
extern t_ullint		ft_minu(t_ullint a1, t_ullint a2);
extern double		ft_maxd(double a1, double a2);
extern double		ft_mind(double a1, double a2);
extern float		ft_maxf(float a1, float a2);
extern float		ft_minf(float a1, float a2);

#endif
