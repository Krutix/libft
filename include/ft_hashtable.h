/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:17:14 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/09 06:55:51 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHTABLE_H
# define FT_HASHTABLE_H

# include "ftdef.h"

typedef struct s_ht_key_value
{
	void	*key;
	void	*value;
}				t_ht_key_value;

typedef struct s_hashtable
{
	void		*raw_table;
	t_hash_func	hash;
	t_cmp_func	cmp;
	size_t		capacity;
	size_t		size;
	t_uint		key_size;
	t_uint		value_size;
}				t_hashtable;

# define FT_HT_START_SIZE 16
# define FT_HT_SCALE_MULTI 2.

typedef struct s_ht_construct_args
{
	t_uint		key_size;
	t_uint		value_size;
	t_hash_func	hashfunc;
	t_cmp_func	cmpfunc;
}				t_ht_construct_args;

void		ft_ht_construct(t_hashtable *ht, t_ht_construct_args args);
void		ft_ht_destruct(t_hashtable *ht, \
					t_destr_func key_destr, \
					t_destr_func value_destr);

t_ft_err	ft_ht_rehash(t_hashtable *ht, size_t new_capacity);
void		*ft_ht_find(t_hashtable *ht, void *key);
void		*ft_ht_insert_or_assign(t_hashtable *ht, \
							void *key, void *data);
void		*ft_ht_insert(t_hashtable *ht, void *key, void *data);
void		*ft_ht_insert_c(t_hashtable *ht, void *key,
				t_construct construct, void *constr_data);
void		ft_ht_remove(t_hashtable *ht, void *key, \
	t_destr_func key_destr, t_destr_func value_destr);

size_t		ft_hash_int(int *i);
size_t		ft_hash_str(char **str);

#endif
