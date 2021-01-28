#include "ft_math.h"

#define FTST_SUB_TEST
#include "ftst.h"
#include "limits.h"

TEST(ft_swap_basic)
{
    int a = 'a', b = 'b';
    ft_swap_1((int8_t*)&a, (int8_t*)&b);
    EQ(a, 'b', c);
    EQ(b, 'a', c);
    EQ(a, 'b', i);
    EQ(b, 'a', i);
}

TEST(ft_swap_big_swap)
{
	typedef struct	test_1 {
		size_t	cell0;
		size_t	cell1;
		size_t	cell2;
		t_uchar	k;
	}				t_test_1;
	t_test_1 a, b;
	a = (t_test_1) {0, 0, 0, 0};
	b = (t_test_1) {UINT64_MAX, UINT64_MAX, UINT64_MAX, UINT8_MAX};
	ft_swap_n(&a, &b, sizeof(size_t) * 3);
    EQ(a.cell0, UINT64_MAX, llu);
    EQ(a.cell1, UINT64_MAX, llu);
    EQ(a.cell2, UINT64_MAX, llu);
    EQ(b.cell0, 0, llu);
    EQ(b.cell1, 0, llu);
    EQ(b.cell2, 0, llu);
	EQ(a.k, 0);
	EQ(b.k, UINT8_MAX);
	ft_swap_n(&a, &b, sizeof(size_t) * 3 + 1);
    EQ(b.cell0, UINT64_MAX, llu);
    EQ(b.cell1, UINT64_MAX, llu);
    EQ(b.cell2, UINT64_MAX, llu);
    EQ(a.cell0, 0, llu);
    EQ(a.cell1, 0, llu);
    EQ(a.cell2, 0, llu);
	EQ(a.k, UINT8_MAX);
	EQ(b.k, 0);
}
