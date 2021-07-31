#include "ft_hashtable.h"
#include "ftst.h"
#include "ft_math.h"

size_t fake_hash_num(int *num)
{
	return *num;
}

int cmp_ints(int *a, int *b)
{
	return *a - *b;
}

TEST(ft_ht_construct)
{
	t_hashtable ht;
	ft_ht_construct(&ht, (t_ht_construct_args){ \
		sizeof(int), sizeof(char), \
		(t_hashfunc)fake_hash_num, (t_cmpfunc)cmp_ints});
	EQ(ht.key_size, sizeof(int), u);
	EQ(ht.value_size, sizeof(char), u);
	EQ(ht.cmp, cmp_ints, p);
	EQ(ht.hash, fake_hash_num, p);
	EQ(ht.capacity, 0);
	EQ(ht.size, 0);
	EQ(ht.raw_table, NULL, p);

	int a = 0;
	char ch = 'a';
	NE(ft_ht_insert(&ht, &a, &ch), NULL, p, ASSERT);
	a = 16;
	ch = 'b';
	NE(ft_ht_insert(&ht, &a, &ch), NULL, p, ASSERT);
	a = 32;
	ch = 'c';
	NE(ft_ht_insert(&ht, &a, &ch), NULL, p, ASSERT);

	NE(ft_ht_find(&ht, &a), NULL, p, ASSERT);
	EQ('c', *(char *)ft_ht_find(&ht, &a), c);
	a = 16;
	NE(ft_ht_find(&ht, &a), NULL, p, ASSERT);
	EQ('b', *(char *)ft_ht_find(&ht, &a), c);
	a = 0;
	NE(ft_ht_find(&ht, &a), NULL, p, ASSERT);
	EQ('a', *(char *)ft_ht_find(&ht, &a), c);

	ft_ht_destruct(&ht, NULL, NULL);
}
