#ifndef FT_ALGORITHM_H
# define FT_ALGORITHM_H

# include "ftdef.h"

void	ft_qsort(void *begin, void *end, \
			size_t size_of_cell, t_bool (*lower)());

void	ft_swap_n(void *v1, void *v2, size_t size);
void	ft_swap_8(int64_t *v1, int64_t *v2);
void	ft_swap_4(int32_t *v1, int32_t *v2);
void	ft_swap_2(int16_t *v1, int16_t *v2);
void	ft_swap_1(int8_t *v1, int8_t *v2);

#endif