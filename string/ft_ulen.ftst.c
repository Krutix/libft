#include "ft_string.h"

#define FTST_SUB_TEST
#include "ftst.h"

TEST(ft_ulen_basic)
{
	EQ(ft_ulen(0), 1);
	EQ(ft_ulen(1), 1);
	EQ(ft_ulen(9), 1);
	EQ(ft_ulen(10), 2);
	EQ(ft_ulen(UINT64_MAX), 20);
	int k = 20;
	for (t_ullint i = UINT64_MAX; i != 0; i /= 10)
		EQ(ft_ulen(i), k--);
}

TEST(ft_ulen_hex)
{
	EQ(ft_ulen_16(0), 1);
	EQ(ft_ulen_16(1), 1);
	EQ(ft_ulen_16(16), 2);
	EQ(ft_ulen_16(15), 1);
	EQ(ft_ulen_16(UINT64_MAX), 16);
	int k = 16;
	for (t_ullint i = UINT64_MAX; i != 0; i /= 16)
		EQ(ft_ulen_16(i), k--);
}

TEST(ft_ulen_oct)
{
	EQ(ft_ulen_8(0), 1);
	EQ(ft_ulen_8(1), 1);
	EQ(ft_ulen_8(8), 2);
	EQ(ft_ulen_8(7), 1);
	EQ(ft_ulen_8(UINT64_MAX), 22);
	int k = 22;
	for (t_ullint i = UINT64_MAX; i != 0; i /= 8)
		EQ(ft_ulen_8(i), k--);
}

TEST(ft_ulen_b)
{
	EQ(ft_ulen_2(0), 1);
	EQ(ft_ulen_2(1), 1);
	EQ(ft_ulen_2(2), 2);
	EQ(ft_ulen_2(UINT64_MAX), 64);
	int k = 64;
	for (t_ullint i = UINT64_MAX; i != 0; i >>= 1)
		EQ(ft_ulen_2(i), k--, u, ASSERT);
}
