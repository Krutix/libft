#include <stddef.h>
#include "ft_vector.h"

void		ft_vec_constructor(t_vector **vec)
{
	*vec = malloc(sizeof(t_vector));
	if (!*vec)
		return ;
	(*vec)->size = 0;
	(*vec)->array = NULL;
	(*vec)->reserv = 4;
	ft_vec_realloc(*vec, (*vec)->reserv);
}
