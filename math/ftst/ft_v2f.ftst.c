#include "ftst.h"
#include "ft_math.h"

TEST(ft_v2f_fnorm)
{
    EQ(ft_v2f_mag(ft_v2f_fnorm((t_vec_2f){ 10.f, 10.f })), 1., ff);
    EQ(ft_v2f_mag(ft_v2f_fnorm((t_vec_2f){ 10.f, 5.f })), 1., ff);
    EQ(ft_v2f_mag(ft_v2f_fnorm((t_vec_2f){ 10.f, 3.f })), 1., ff);
    EQ(ft_v2f_mag(ft_v2f_fnorm((t_vec_2f){ 1.f, 1.f })), 1., ff);
}

TEST(ft_v2f_norm)
{
    EQ(ft_v2f_mag(ft_v2f_norm((t_vec_2f){ 10.f, 10.f })), 1., ff);
    EQ(ft_v2f_mag(ft_v2f_norm((t_vec_2f){ 10.f, 5.f })), 1., ff);
    EQ(ft_v2f_mag(ft_v2f_norm((t_vec_2f){ 10.f, 3.f })), 1., ff);
    EQ(ft_v2f_mag(ft_v2f_norm((t_vec_2f){ 1.f, 1.f })), 1., ff);
}
