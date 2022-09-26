#include "ft_vector.h"
#include "ftst.h"

TEST(ft_vec_construct)
{
    t_vector vec;
    ft_vec_construct(&vec, 1);

    EQ(vec.array, NULL, p);
    EQ(vec.cell_size, 1, u);
    EQ(vec.size, 0, u);
    EQ(vec.reserv, 0, u);
}
