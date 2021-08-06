#include "__ft_hashtable.h"

void	ft_ht_remove(t_hashtable *ht, void *key, \
	t_destrfunc key_destr, t_destrfunc value_destr)
{
	char			*ht_statuses;
	size_t			pos;
	size_t			cells_processed;
	t_ht_key_value	kv;

	ht_statuses = ht->raw_table;
	pos = ht->hash(key) % ht->capacity;
	cells_processed = 0;
	while (cells_processed < ht->capacity && \
			(ht_statuses[pos] == e_ht_cs_used || \
			(ht_statuses[pos] == e_ht_cs_engaged && \
			ht->cmp(__ft_ht_at(ht, pos).key, key) != 0)))
	{
		pos = (pos + 1) % ht->capacity;
		cells_processed++;
	}
	if (ht_statuses[pos] != e_ht_cs_engaged || \
			cells_processed == ht->capacity)
		return ;
	ht_statuses[pos] = e_ht_cs_used;
	kv = __ft_ht_at(ht, pos);
	ht->size--;
	if (key_destr)
		key_destr(kv.key);
	if (value_destr)
		value_destr(kv.value);
}
