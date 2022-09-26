#include "ft_string.h"

#include "ftst.h"

TEST(ft_split)
{
    char* sp = "------------...-----------";
    char ** re = ft_split(sp, ".");
    NE(re[0], NULL, p, ASSERT);
    STR_EQ(re[0], "------------");
    NE(re[1], NULL, p, ASSERT);
    STR_EQ(re[1], "-----------");

    sp = "NO    ./resources/Walls/xpm/0.xpm";
    re = ft_split(sp, " ");
    NE(re[0], NULL, p, ASSERT);
    STR_EQ(re[0], "NO");

    NE(re[1], NULL, p, ASSERT);
    STR_EQ(re[1], "./resources/Walls/xpm/0.xpm");
}
