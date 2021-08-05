#ifndef __FT_HASHTABLE_H
# define __FT_HASHTABLE_H

# include "ft_hashtable.h"

enum ht_cell_status
{
	e_ht_cs_free,
	e_ht_cs_engaged,
	e_ht_cs_used
};

t_ht_key_value	__ft_ht_at(t_hashtable *ht, size_t pos);
t_bool			__ft_ht_reserv(t_hashtable *ht);
size_t			__ft_ht_find_free_by_key(t_hashtable *ht, void *key);

#endif
