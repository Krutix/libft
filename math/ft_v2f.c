#include "ft_math.h"
#include "math.h"

float       ft_v2f_mag(t_vec_2f vec)
{
    return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

void        ft_v2f_mul_f(t_vec_2f *vec, float mul)
{
    vec->x *= mul;
    vec->y *= mul;
}

t_vec_2f        ft_v2f_norm(t_vec_2f vec)
{
    float const mag = ft_v2f_mag(vec);
    float const fmag = 1. / mag;

    return ((t_vec_2f){ vec.x * fmag, vec.y * fmag});
}

t_vec_2f        ft_v2f_fnorm(t_vec_2f vec)
{
    float const ax = ft_absf(vec.x);
    float const ay = ft_absf(vec.y);
    float       ratio;

    ratio = 1 / ft_maxf(ax, ay);
    ratio = ratio * (1.29289 - (ax + ay) * ratio * 0.29289);
    return ((t_vec_2f){ vec.x * ratio, vec.y * ratio});
}
