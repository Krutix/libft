#include "ft_vector.h"

void	*ft_vec_pop_back(t_vector *vec)
{
	return (vec->array[--vec->size]);
}