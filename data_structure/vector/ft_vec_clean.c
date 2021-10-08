#include "ft_vector.h"

void	ft_vec_clean(t_vector *vec, t_destr_func del)
{
	ft_vec_foreach(vec, del);
	vec->size = 0;
}
