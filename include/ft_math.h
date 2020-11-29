#ifndef FT_MATH_H
#define FT_MATH_H

#include "ftdef.h"

ullint	ft_abs(llint num);
t_bool	ft_is_prime(ullint num);
llint	ft_pow(llint num, size_t pow);
ullint	ft_sqrt(ullint nb);

void	ft_swap_64(int64_t *v1, int64_t *v2);
void	ft_swap_32(int32_t *v1, int32_t *v2);
void	ft_swap_16(int16_t *v1, int16_t *v2);
void	ft_swap_8(int8_t *v1, int8_t *v2);

#endif