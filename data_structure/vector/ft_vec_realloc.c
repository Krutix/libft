#include <stdlib.h>
#include "ft_string.h"
#include "ft_vector.h"

t_bool	ft_vec_realloc(t_vector *vec, size_t new_reserv)
{
	void	*new_arr;

	new_arr = malloc(new_reserv * vec->cell_size);
	if (!new_arr)
		return (t_false);
	if (vec->size > new_reserv)
		vec->size = new_reserv;
	ft_memcpy(new_arr, vec->array, vec->size * vec->cell_size);
	if (vec->array)
		free(vec->array);
	vec->reserv = new_reserv;
	vec->array = new_arr;
	return (t_true);
}

t_bool	ft_vec_resize(t_vector *vec, size_t new_reserv)
{
	return (ft_vec_realloc(vec, new_reserv));
}
