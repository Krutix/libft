#include "ftst.h"
#include "ft_math.h"

TEST(ft_v2f_fnorm)
{
    t_vec_2f v = (t_vec_2f){ 10.f, 10.f };
    EQ(ft_v2f_mag(*ft_v2f_fnorm(&v)), 1., f);

    v = (t_vec_2f){ 10.f, 5.f };
    EQ(ft_v2f_mag(*ft_v2f_fnorm(&v)), 1., f);

    v = (t_vec_2f){ 1.f, 1.f };
    EQ(ft_v2f_mag(*ft_v2f_fnorm(&v)), 1., f);
}

TEST(ft_v2f_norm)
{
    t_vec_2f v = (t_vec_2f){ 10.f, 10.f };
    EQ(ft_v2f_mag(*ft_v2f_norm(&v)), 1., f);

    v = (t_vec_2f){ 10.f, 5.f };
    EQ(ft_v2f_mag(*ft_v2f_norm(&v)), 1., f);

    v = (t_vec_2f){ 1.f, 1.f };
    EQ(ft_v2f_mag(*ft_v2f_fnorm(&v)), 1., f);
}
