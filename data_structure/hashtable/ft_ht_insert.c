#include "__ft_hashtable.h"
#include "ft_string.h"

t_bool	__ft_ht_reserv(t_hashtable *ht)
{
	if (ht->size == ht->capacity)
	{
		if (ht->capacity == 0)
		{
			if (!ft_ht_rehash(ht, FT_HT_START_SIZE))
				return (t_false);
		}
		else
		{
			if (!ft_ht_rehash(ht, ht->capacity * FT_HT_SCALE_MULTI))
				return (t_false);
		}
	}
	return (t_true);
}

void	*ft_ht_insert(t_hashtable *ht, void *key, void *value)
{
	char			*ht_statuses;
	size_t			pos;
	t_ht_key_value	kv;

	if (!__ft_ht_reserv(ht))
		return (NULL);
	ht_statuses = ht->raw_table;
	pos = ht->hash(key) % ht->capacity;
	while (ht_statuses[pos] == e_ht_cs_engaged && \
			ht->cmp(__ft_ht_at(ht, pos).key, key) != 0)
	{
		pos = (pos + 1) % ht->capacity;
	}
	ht_statuses[pos] = e_ht_cs_engaged;
	kv = __ft_ht_at(ht, pos);
	ft_memcpy(kv.key, key, ht->key_size);
	if (value)
		ft_memcpy(kv.value, value, ht->value_size);
	ht->size++;
	return (kv.value);
}
