#include "ftst.h"
#include "ft_math.h"
#include <limits.h>

TEST(ft_abs)
{
    EQ(ft_abs(10), 10, llu);
    EQ(ft_abs(INT64_MAX), INT64_MAX, llu);
    EQ(ft_abs(-10), 10, llu);
    EQ(ft_abs(INT64_MIN), -(__int128_t)INT64_MIN, llu);
}

TEST(ft_absf)
{
    EQ(ft_absf(10.f), 10.f, g);
    EQ(ft_absf(-10.f), 10.f, g);
    EQ(ft_absf(-0.f), 0.f, g);
    EQ(ft_absf(-105432598273459.f), 105432598273459.f, g);
    EQ(ft_absf(-__FLT_MAX__), __FLT_MAX__, g);
}
