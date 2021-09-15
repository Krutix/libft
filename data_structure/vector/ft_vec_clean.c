#include "ft_vector.h"

void	ft_vec_clean(t_vector *vec, void (*fr)(void *))
{
	ft_vec_foreach(vec, fr);
	vec->size = 0;
}
