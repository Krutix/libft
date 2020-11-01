#include "ft_vector.h"

void	*ft_vec_returndel(t_vector *vec, void (*del)(void *))
{
	ft_vec_destructor(vec, del);
	return (NULL);
}