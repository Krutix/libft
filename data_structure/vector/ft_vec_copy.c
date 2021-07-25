#include "ft_vector.h"

t_bool	ft_vec_copy_construct(t_vector *copy, t_vector *sample)
{
	copy->size = sample->size;
	copy->capacity = sample->size;
	copy->cell_size = sample->cell_size;
	copy->array = malloc(sample->size * sample->cell_size);
	ft_memcpy(copy->array, sample->array, \
		sample->size * sample->cell_size);
}