#include "ft_math.h"
#include "math.h"

float           ft_v2f_mag(t_v2f vec)
{
    return (sqrtf(vec.x * vec.x + vec.y * vec.y));
}

float           ft_v2f_sqmag(t_v2f vec)
{
    return (vec.x * vec.x + vec.y * vec.y);
}

t_v2f        ft_v2f_norm(t_v2f vec)
{
    float const mag = 1.f / ft_v2f_mag(vec);

    return ((t_v2f){ vec.x * mag, vec.y * mag});
}

t_v2f        ft_v2f_fnorm(t_v2f vec)
{
    float const ax = ft_absf(vec.x);
    float const ay = ft_absf(vec.y);
    float       ratio;

    ratio = 1.f / ft_maxf(ax, ay);
    ratio = ratio * (1.29289f - (ax + ay) * ratio * 0.29289f);
    return ((t_v2f){ vec.x * ratio, vec.y * ratio});
}
