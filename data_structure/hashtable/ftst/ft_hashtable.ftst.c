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

t_bool g_ch[40];
t_bool g_nbr[40];
t_bool dbl_nbr_free;
t_bool dbl_ch_free;

void nbr_del(int *nbr)
{
	if (g_nbr[*nbr])
		dbl_nbr_free = t_true;
	g_nbr[*nbr] = t_true;
}

void ch_del(char *ch)
{
	if (g_ch[*ch - ' '])
		dbl_ch_free = t_true;
	g_ch[*ch - ' '] = t_true;
}

TEST(ft_ht_rehash_test)
{
	t_hashtable ht;
	ft_ht_construct(&ht, (t_ht_construct_args){ \
		sizeof(int), sizeof(char), \
		(t_hashfunc)fake_hash_num, (t_cmpfunc)cmp_ints});

	size_t	nbr = 0;
	char	ch = ' ';
	for (size_t i = 0; i < 40; i++)
	{
		NE(ft_ht_insert(&ht, &nbr, &ch), NULL, p, ASSERT);
		nbr++;
		ch++;
	}
	nbr = 0;
	ch = ' ';
	for (size_t i = 0; i < 40; i++)
	{
		NE(ft_ht_find(&ht, &nbr), NULL, p, ASSERT);
		EQ(ch, *(char *)ft_ht_find(&ht, &nbr), c);
		nbr++;
		ch++;
	}
	ft_ht_destruct(&ht, \
		(t_destrfunc)nbr_del, (t_destrfunc)ch_del);
	EQ(dbl_ch_free, t_false, c);
	EQ(dbl_nbr_free, t_false, c);
	for (size_t i = 0; i < 40; i++)
	{
		EQ(g_nbr[i], t_true, c);
		EQ(g_ch[i], t_true, c);
	}
}
