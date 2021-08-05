#include "__ft_hashtable.h"

void	*ft_ht_find(t_hashtable *ht, void *key)
{
	char			*ht_statuses;
	size_t			pos;
	size_t			cells_processed;
	t_ht_key_value	kv;

	ht_statuses = ht->raw_table;
	pos = ht->hash(key) % ht->capacity;
	cells_processed = 0;
	while (cells_processed < ht->capacity && \
			ht_statuses[pos] != e_ht_cs_free)
	{
		if (ht_statuses[pos] == e_ht_cs_engaged && \
			ht->cmp(__ft_ht_at(ht, pos).key, key) == 0)
		{
			kv = __ft_ht_at(ht, pos);
			return (kv.value);
		}
		pos = (pos + 1) % ht->capacity;
		cells_processed++;
	}
	return (NULL);
}
