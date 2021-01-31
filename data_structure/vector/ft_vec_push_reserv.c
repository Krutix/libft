#include "ft_vector.h"

t_bool		ft_vec_push_reserv(t_vector *vec)
{
	if (vec->reserv == vec->size)
		if (!ft_vec_realloc(vec, vec->reserv != 0 ? vec->reserv * 2 : 4))
			return (t_false);
	return (t_true);
}
