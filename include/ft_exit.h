/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 06:56:20 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/09 06:56:21 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXIT_H
# define FT_EXIT_H

# include <ftdef.h>

t_ft_err	ft_at_exit(void *ptr, t_process_func process);
t_ft_err	ft_unsub_exit(void *ptr);
t_ft_err	ft_exit(int exit_code);

#endif
