#include "ftst.h"
#include "ft_math.h"

TEST(ft_v2f_fnorm)
{
    EQ_A(ft_v2f_mag(ft_v2f_fnorm((t_v2f){ 10.f, 10.f })), 1.f, 0.05f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_fnorm((t_v2f){ 10.f,  9.f })), 1.f, 0.05f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_fnorm((t_v2f){ 10.f,  8.f })), 1.f, 0.05f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_fnorm((t_v2f){ 10.f,  7.f })), 1.f, 0.05f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_fnorm((t_v2f){ 10.f,  6.f })), 1.f, 0.05f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_fnorm((t_v2f){ 10.f,  5.f })), 1.f, 0.05f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_fnorm((t_v2f){ 10.f,  4.f })), 1.f, 0.05f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_fnorm((t_v2f){ 10.f,  3.f })), 1.f, 0.05f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_fnorm((t_v2f){ 10.f,  2.f })), 1.f, 0.05f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_fnorm((t_v2f){ 10.f,  1.f })), 1.f, 0.05f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_fnorm((t_v2f){ 10.f,  .0f })), 1.f, 0.05f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_fnorm((t_v2f){  1.f,  1.f })), 1.f, 0.05f, ff);
}

TEST(ft_v2f_norm)
{
    EQ_A(ft_v2f_mag(ft_v2f_norm((t_v2f){ 10.f, 10.f })), 1.f, 0.00000005f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_norm((t_v2f){ 10.f,  9.f })), 1.f, 0.00000005f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_norm((t_v2f){ 10.f,  8.f })), 1.f, 0.00000005f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_norm((t_v2f){ 10.f,  7.f })), 1.f, 0.00000005f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_norm((t_v2f){ 10.f,  6.f })), 1.f, 0.00000005f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_norm((t_v2f){ 10.f,  5.f })), 1.f, 0.00000005f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_norm((t_v2f){ 10.f,  4.f })), 1.f, 0.00000005f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_norm((t_v2f){ 10.f,  3.f })), 1.f, 0.00000005f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_norm((t_v2f){ 10.f,  2.f })), 1.f, 0.00000005f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_norm((t_v2f){ 10.f,  1.f })), 1.f, 0.00000005f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_norm((t_v2f){ 10.f,  .0f })), 1.f, 0.00000005f, ff);
    EQ_A(ft_v2f_mag(ft_v2f_norm((t_v2f){  1.f,  1.f })), 1.f, 0.00000005f, ff);
}
