#ifndef __CHARENUM_H
# define __CHARENUM_H

#include <ftdef.h>

typedef int64_t t_chenum[4];
#define CHENUM_CSIZE	((sizeof(t_chenum) / 4) * 8)


void	chenum_set(t_chenum *chenum, char ch);
void	chenum_multset(t_chenum *chenum, char *chset);

void	chenum_unset(t_chenum *chenum, char ch);
void	chenum_multunset(t_chenum *chenum, char *chset);

bool	chenum_is(t_chenum *chenum, char ch);
void	chenum_clean(t_chenum *chenum);
void	chenum_inv(t_chenum *chenum);

#endif
