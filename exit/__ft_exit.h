#ifndef __FT_EXIT_H
# define __FT_EXIT_H

# include <ftdef.h>

typedef struct s_exit_sub
{
    void            *ptr;
    t_process_func  process;
}               t_exit_sub;

#endif
