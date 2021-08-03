#include "ft_hashtable.h"

size_t	ft_hash_int(int *i)
{
	return (*i ^ (*i << 1));
}

size_t	ft_hash_str(char *str)
{
	size_t	hash;
	size_t	idx;

	hash = 0;
	idx = 0;
	while (str[idx])
	{
		hash += str[idx] * (idx + 1);
		idx++;
	}
}
