#include "ft_math.h"

#define FTST_SUB_TEST
#include "ftst.h"

TEST(ft_swap_basic)
{
    char a = 'a', b = 'b';
    ft_swap_1(&a, &b);
    EQ(a, 'b', c);
    EQ(b, 'a', c);
}
