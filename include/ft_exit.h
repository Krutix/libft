#ifndef FT_EXIT_H
# define FT_EXIT_H

#include <ftdef.h>

t_ft_err	ft_at_exit(void *ptr, t_process_func process);
t_ft_err	ft_unsub_exit(void *ptr);
t_ft_err	ft_exit(int exit_code);

#endif
