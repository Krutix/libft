#ifndef FT_MATH_H
# define FT_MATH_H

# include "ftdef.h"

ullint	ft_abs(llint num);
t_bool	ft_is_prime(ullint num);
llint	ft_pow(llint num, size_t pow);
ullint	ft_sqrt(ullint nb);

void	ft_swap_n(void *v1, void *v2, size_t size);
void	ft_swap_8(int64_t *v1, int64_t *v2);
void	ft_swap_4(int32_t *v1, int32_t *v2);
void	ft_swap_2(int16_t *v1, int16_t *v2);
void	ft_swap_1(int8_t *v1, int8_t *v2);

llint	ft_maxi(llint a1, llint a2);
llint	ft_mini(llint a1, llint a2);

#endif