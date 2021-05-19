#ifndef FT_ALGORITHM_H
# define FT_ALGORITHM_H

# include "ftdef.h"

void	ft_qsort(void *begin, void *end, \
			size_t size_of_cell, t_bool (*lower)());

#endif