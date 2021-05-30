#include "ft_vector.h"

void	*ft_vec_fetch_array(t_vector *vec, size_t *out_size)
{
	void	*array;

	array = vec->array;
	if (out_size)
		*out_size = vec->size;
	vec->array = NULL;
	vec->size = 0;
	vec->reserv = 0;
	return (array);
}
