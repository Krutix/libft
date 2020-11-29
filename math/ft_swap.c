#include "ftdef.h"

void	ft_swap_64(int64_t *v1, int64_t *v2)
{
	*v1 ^= *v2;
	*v2 ^= *v1;
	*v1 ^= *v2;
}

void	ft_swap_32(int32_t *v1, int32_t *v2)
{
	*v1 ^= *v2;
	*v2 ^= *v1;
	*v1 ^= *v2;
}

void	ft_swap_16(int16_t *v1, int16_t *v2)
{
	*v1 ^= *v2;
	*v2 ^= *v1;
	*v1 ^= *v2;
}

void	ft_swap_8(int8_t *v1, int8_t *v2)
{
	*v1 ^= *v2;
	*v2 ^= *v1;
	*v1 ^= *v2;
}
