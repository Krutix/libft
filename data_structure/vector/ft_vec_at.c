#include "ft_vector.h"

void	*ft_vec_at(t_vector *vec, size_t pos)
{
	return (vec->array + (pos * vec->cell_size));
}

void	*ft_vec_back(t_vector *vec)
{
	return (ft_vec_at(vec, vec->size - 1));
}

void	*ft_vec_front(t_vector *vec)
{
	return (vec->array);
}
