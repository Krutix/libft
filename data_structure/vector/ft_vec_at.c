#include "ft_vector.h"

void	*ft_vec_at(t_vector *vec, size_t pos)
{
	return (vec->array + (pos * vec->cell_size));
}