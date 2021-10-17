#include "__charenum.h"
#include <ft_string.h>

void	chenum_set(t_chenum *chenum, char ch)
{
	(*chenum)[ch / CHENUM_CSIZE] |= 1 << (ch % CHENUM_CSIZE);
}

void	chenum_multset(t_chenum *chenum, char *chset)
{
	while (*chset)
	{
		chenum_set(chenum, *chset);
		chset++;
	}
}

void	chenum_unset(t_chenum *chenum, char ch)
{
	(*chenum)[ch / CHENUM_CSIZE] &= ~(1 << (ch % CHENUM_CSIZE));
}

void	chenum_multunset(t_chenum *chenum, char *chset)
{
	while (*chset)
	{
		chenum_unset(chenum, *chset);
		chset++;
	}
}

t_bool	chenum_is(t_chenum *chenum, char ch)
{
	return (!!((*chenum)[ch / CHENUM_CSIZE] & (1 << (ch % CHENUM_CSIZE))));
}

void	chenum_clean(t_chenum *chenum)
{
	ft_bzero(chenum, sizeof(t_chenum));
}

void	chenum_inv(t_chenum *chenum)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		(*chenum)[i] ^= (*chenum)[i];
		i++;
	}
}

