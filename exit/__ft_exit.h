/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_exit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 06:58:58 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/09 06:58:59 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_EXIT_H
# define __FT_EXIT_H

# include <ftdef.h>

typedef struct s_exit_sub
{
	void			*ptr;
	t_process_func	process;
}				t_exit_sub;

#endif
