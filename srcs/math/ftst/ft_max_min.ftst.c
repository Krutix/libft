#include "ftst.h"
#include "ft_math.h"

TEST(ft_max_min)
{
    EQ(ft_maxi(INT64_MAX, 0), INT64_MAX, lli);
    EQ(ft_maxi(0, INT64_MAX), INT64_MAX, lli);
    EQ(ft_mini(INT64_MAX, 0), 0, lli);
    EQ(ft_mini(0, INT64_MAX), 0, lli);

    EQ(ft_maxu(UINT64_MAX, 0), UINT64_MAX, llu);
    EQ(ft_maxu(0, UINT64_MAX), UINT64_MAX, llu);
    EQ(ft_minu(UINT64_MAX, 0), 0, llu);
    EQ(ft_minu(0, UINT64_MAX), 0, llu);

    EQ(ft_maxd(__DBL_MAX__, 0.), __DBL_MAX__, f);
    EQ(ft_maxd(0., __DBL_MAX__), __DBL_MAX__, f);
    EQ(ft_mind(__DBL_MAX__, 0.), 0., f);
    EQ(ft_mind(0., __DBL_MAX__), 0., f);

    EQ(ft_maxf(__FLT_MAX__, 0.f), __FLT_MAX__, ff);
    EQ(ft_maxf(0.f, __FLT_MAX__), __FLT_MAX__, ff);
    EQ(ft_minf(__FLT_MAX__, 0.f), 0.f, ff);
    EQ(ft_minf(0.f, __FLT_MAX__), 0.f, ff);
}
