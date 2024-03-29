/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_construct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:22:32 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:24:04 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_hashtable.h"
#include <stdlib.h>

void	ft_ht_construct(t_hashtable *ht, t_ht_construct_args args)
{
	ht->raw_table = NULL;
	ht->hash = args.hashfunc;
	ht->cmp = args.cmpfunc;
	ht->size = 0;
	ht->capacity = 0;
	ht->key_size = args.key_size;
	ht->value_size = args.value_size;
}

t_ht_key_value	__ft_ht_at(t_hashtable *ht, size_t pos)
{
	size_t const	cell_size = ht->key_size + ht->value_size;
	t_ht_key_value	key_value;

	key_value.key = ht->raw_table + ht->capacity + cell_size * pos;
	key_value.value = key_value.key + ht->key_size;
	return (key_value);
}

void	ft_ht_destruct(t_hashtable *ht, \
	t_destr_func key_destr, t_destr_func value_destr)
{
	char			*ht_statuses;
	size_t			idx;
	t_ht_key_value	kv;

	ht_statuses = ht->raw_table;
	idx = 0;
	if (key_destr || value_destr)
	{
		while (idx < ht->capacity)
		{
			if (ht_statuses[idx] == e_ht_cs_engaged)
			{
				kv = __ft_ht_at(ht, idx);
				if (key_destr)
					key_destr(kv.key);
				if (value_destr)
					value_destr(kv.value);
			}
			idx++;
		}
	}
	free(ht->raw_table);
}
