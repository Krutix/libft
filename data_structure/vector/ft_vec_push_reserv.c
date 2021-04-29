#include "ft_vector.h"

t_bool	ft_vec_push_reserv(t_vector *vec)
{
	size_t	alloc_size;

	if (vec->reserv == vec->size)
	{
		alloc_size = vec->reserv * 2;
		if (alloc_size == 0)
			alloc_size = 4;
		if (!ft_vec_realloc(vec, alloc_size))
			return (t_false);
	}
	return (t_true);
}
