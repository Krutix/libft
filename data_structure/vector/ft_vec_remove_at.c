#include "ft_vector.h"
#include "ft_string.h"

void ft_vec_remove_at(t_vector *vec, size_t pos, void (*del)(void*))
{
    if (del)
        del(ft_vec_at(vec, pos));
    ft_memmove(ft_vec_at(vec, pos), ft_vec_at(vec, pos + 1),
            (vec->size - 1 - pos) * vec->cell_size);
    vec->size--;
}