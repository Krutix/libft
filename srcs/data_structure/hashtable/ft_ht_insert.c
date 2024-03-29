/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:22:43 by fdiego            #+#    #+#             */
/*   Updated: 2021/08/06 17:22:44 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_hashtable.h"
#include "ft_string.h"

void	*ft_ht_insert(t_hashtable *ht, void *key, void *value)
{
	t_ht_key_value	kv;
	char			*ht_statuses;
	size_t			pos;

	if (__ft_ht_reserv(ht) != ft_err_ok)
		return (NULL);
	ht_statuses = ht->raw_table;
	pos = __ft_ht_find_free_by_key(ht, key);
	kv = __ft_ht_at(ht, pos);
	if (ht_statuses[pos] != e_ht_cs_engaged)
	{
		ht_statuses[pos] = e_ht_cs_engaged;
		ft_memcpy(kv.key, key, ht->key_size);
		if (value)
			ft_memcpy(kv.value, value, ht->value_size);
		else
			ft_bzero(kv.value, ht->value_size);
		ht->size++;
	}
	return (kv.value);
}

void	*ft_ht_insert_c(t_hashtable *ht, void *key, \
			t_construct constr, void *constr_data)
{
	t_ht_key_value	kv;
	char			*ht_statuses;
	size_t			pos;

	if (__ft_ht_reserv(ht) != ft_err_ok)
		return (NULL);
	ht_statuses = ht->raw_table;
	pos = __ft_ht_find_free_by_key(ht, key);
	kv = __ft_ht_at(ht, pos);
	if (ht_statuses[pos] != e_ht_cs_engaged)
	{
		ht_statuses[pos] = e_ht_cs_engaged;
		ft_memcpy(kv.key, key, ht->key_size);
		constr(kv.value, constr_data);
		ht->size++;
	}
	return (kv.value);
}
