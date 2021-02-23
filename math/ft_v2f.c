#include "ft_math.h"
#include "math.h"

float           ft_v2f_mag(t_vec_2f vec)
{
    return (sqrtf(vec.x * vec.x + vec.y * vec.y));
}

t_vec_2f        ft_v2f_norm(t_vec_2f vec)
{
    float const mag = ft_v2f_mag(vec);
    float const fmag = 1.f / mag;

    return ((t_vec_2f){ vec.x * fmag, vec.y * fmag});
}

t_vec_2f        ft_v2f_fnorm(t_vec_2f vec)
{
    float const ax = ft_absf(vec.x);
    float const ay = ft_absf(vec.y);
    float       ratio;

    ratio = 1.f / ft_maxf(ax, ay);
    ratio = ratio * (1.29289f - (ax + ay) * ratio * 0.29289f);
    return ((t_vec_2f){ vec.x * ratio, vec.y * ratio});
}
