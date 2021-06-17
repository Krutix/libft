#include <stdlib.h>
#include "ft_vector.h"

void	ft_vec_construct(t_vector *vec, t_uint cell_size)
{
	vec->cell_size = cell_size;
	vec->size = 0;
	vec->capacity = 0;
	vec->array = NULL;
}
