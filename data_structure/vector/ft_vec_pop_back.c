#include "ft_vector.h"

void	ft_vec_pop_back(t_vector *vec, void (*del)(void*))
{
	if (del)
		del(ft_vec_at(vec, 0));
	vec->size--;
}
