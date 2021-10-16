/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_rehash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:22:46 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:23:09 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_hashtable.h"
#include "ft_string.h"
#include "stdlib.h"

static t_ft_err	rehash_error(t_hashtable *ht, t_hashtable *old_ht)
{
	*ht = *old_ht;
	return (ft_err_bad_alloc);
}

t_ft_err	ft_ht_rehash(t_hashtable *ht, size_t new_capacity)
{
	t_hashtable		old_ht;
	char			*ht_statuses;
	t_ht_key_value	kv;
	size_t			idx;

	old_ht = *ht;
	ht->size = 0;
	ht->capacity = new_capacity;
	ht->raw_table = ft_calloc(1, ht->capacity + \
		ht->capacity * (ht->key_size + ht->value_size));
	if (!ht->raw_table)
		return (rehash_error(ht, &old_ht));
	idx = 0;
	ht_statuses = old_ht.raw_table;
	while (idx < old_ht.capacity)
	{
		if (ht_statuses[idx] == e_ht_cs_engaged)
		{
			kv = __ft_ht_at(&old_ht, idx);
			ft_ht_insert(ht, kv.key, kv.value);
		}
		idx++;
	}
	free(old_ht.raw_table);
	return (ft_err_ok);
}
