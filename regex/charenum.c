#include "__charenum.h"
#include <ft_string.h>

t_chenum	*chenum_create(void)
{
	static t_chenum	tbh;

	return (&tbh);
}


t_chenum	*chenum_createst(int ch)
{
	static t_chenum	tbh;

	chenum_clean(&tbh);
	chenum_set(&tbh, ch);
	return (&tbh);
}

t_chenum	*chenum_createmst(char const *chset)
{
	static t_chenum	tbh;

	chenum_clean(&tbh);
	chenum_multset(&tbh, chset);
	return (&tbh);
}

t_chenum	*chenum_set(t_chenum *chenum, int ch)
{
	(*chenum)[ch / CHENUM_CSIZE] |= 1 << (ch % CHENUM_CSIZE);
	return (chenum);
}

t_chenum	*chenum_multset(t_chenum *chenum, char const *chset)
{
	while (*chset)
	{
		chenum_set(chenum, *chset);
		chset++;
	}
	return (chenum);
}

t_chenum	*chenum_unset(t_chenum *chenum, int ch)
{
	(*chenum)[ch / CHENUM_CSIZE] &= ~(1 << (ch % CHENUM_CSIZE));
	return (chenum);
}

t_chenum	*chenum_multunset(t_chenum *chenum, char const *chset)
{
	while (*chset)
	{
		chenum_unset(chenum, *chset);
		chset++;
	}
	return (chenum);
}

t_bool	chenum_is(t_chenum const *chenum, int ch)
{
	return (!!((*chenum)[ch / CHENUM_CSIZE] & (1 << (ch % CHENUM_CSIZE))));
}

t_chenum	*chenum_clean(t_chenum *chenum)
{
	ft_bzero(chenum, sizeof(t_chenum));
	return (chenum);
}

t_chenum	*chenum_inv(t_chenum *chenum)
{
	size_t	i;

	i = 0;
	while (i < CHENUM_LEN)
	{
		(*chenum)[i] = ~(*chenum)[i];
		i++;
	}
	return (chenum);
}
