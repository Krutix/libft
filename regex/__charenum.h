#ifndef __CHARENUM_H
# define __CHARENUM_H

#include <ftdef.h>

#define CHENUM_LEN		2
typedef int64_t t_chenum[CHENUM_LEN];
#define CHENUM_CSIZE	((sizeof(t_chenum) / CHENUM_LEN) * 8)

t_chenum	*chenum_create(void);
t_chenum	*chenum_createst(int ch);
t_chenum	*chenum_createmst(char const *chset);

t_chenum	*chenum_set(t_chenum *chenum, int ch);
t_chenum	*chenum_multset(t_chenum *chenum, char const *chset);

t_chenum	*chenum_unset(t_chenum *chenum, int ch);
t_chenum	*chenum_multunset(t_chenum *chenum, char const *chset);

t_chenum	*chenum_clean(t_chenum *chenum);
t_chenum	*chenum_inv(t_chenum *chenum);

t_bool		chenum_is(t_chenum const *chenum, int ch);

#endif
