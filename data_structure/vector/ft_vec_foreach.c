#include "ft_vector.h"

void ft_vec_foreach(t_vector *vec, void (*f)(void *))
{
    size_t  i;

    i = 0;
    while (i < vec->size)
    {
        f(ft_vec_at(vec, i));
        i++;
    }
}