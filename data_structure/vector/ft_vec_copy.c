#include "ft_vector.h"
#include "ft_string.h"

t_bool	ft_vec_copy_construct(t_vector *copy, t_vector *sample)
{
	copy->size = sample->size;
	copy->capacity = sample->size;
	copy->cell_size = sample->cell_size;
	copy->array = malloc(sample->size * sample->cell_size);
	if (!copy->array)
		return (t_false);
	ft_memcpy(copy->array, sample->array, \
		sample->size * sample->cell_size);
	return (t_true);
}
