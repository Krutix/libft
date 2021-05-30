#include <stdlib.h>
#include "ft_vector.h"

void	ft_vec_destructor(t_vector *vec, void (*fr)(void *))
{
	size_t	i;

	if (fr)
	{
		i = 0;
		while (i < vec->size)
			fr(ft_vec_at(vec, i++));
	}
	free(vec->array);
}
