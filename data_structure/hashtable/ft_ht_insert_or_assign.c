/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_insert_or_assign.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:20:14 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:20:14 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_hashtable.h"
#include "ft_string.h"

t_bool	__ft_ht_reserv(t_hashtable *ht)
{
	if (ht->size == ht->capacity)
	{
		if (ht->capacity == 0)
		{
			if (ft_ht_rehash(ht, FT_HT_START_SIZE) != ftE_ok)
				return (t_false);
		}
		else
		{
			if (ft_ht_rehash(ht, ht->capacity * FT_HT_SCALE_MULTI) != ftE_ok)
				return (t_false);
		}
	}
	return (t_true);
}

size_t	__ft_ht_find_free_by_key(t_hashtable *ht, void *key)
{
	char	*ht_statuses;
	size_t	pos;

	ht_statuses = ht->raw_table;
	pos = ht->hash(key) % ht->capacity;
	while (ht_statuses[pos] == e_ht_cs_engaged && \
			ht->cmp(__ft_ht_at(ht, pos).key, key) != 0)
	{
		pos = (pos + 1) % ht->capacity;
	}
	return (pos);
}

void	*ft_ht_insert_or_assign(t_hashtable *ht, void *key, void *value)
{
	t_ht_key_value	kv;
	char			*ht_statuses;
	size_t			pos;

	if (__ft_ht_reserv(ht) != ftE_ok)
		return (NULL);
	ht_statuses = ht->raw_table;
	pos = __ft_ht_find_free_by_key(ht, key);
	ht_statuses[pos] = e_ht_cs_engaged;
	kv = __ft_ht_at(ht, pos);
	ft_memcpy(kv.key, key, ht->key_size);
	if (value)
		ft_memcpy(kv.value, value, ht->value_size);
	else
		ft_bzero(kv.value, ht->value_size);
	ht->size++;
	return (kv.value);
}
