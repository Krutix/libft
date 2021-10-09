/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 07:00:17 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/09 07:00:18 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_exit.h"
#include <ft_vector.h>
#include <stdlib.h>

static t_vector	g_exit_sub = (t_vector){0, 0, NULL, sizeof(t_exit_sub)};

t_ft_err	ft_at_exit(void *ptr, t_process_func process)
{
	t_exit_sub	sub;

	sub.ptr = ptr;
	sub.process = process;
	return (ft_vec_push_back(&g_exit_sub, &sub));
}

static int	sub_cmp(t_exit_sub *sub, void *ptr)
{
	return (sub->ptr - ptr);
}

t_ft_err	ft_unsub_exit(void *ptr)
{
	ft_vec_remove_all(&g_exit_sub, ptr, NULL, (t_cmp_func)sub_cmp);
	return (ft_err_ok);
}

static void	sub_destr(t_exit_sub *sub)
{
	sub->process(sub->ptr);
}

t_ft_err	ft_exit(int exit_code)
{
	ft_vec_destructor(&g_exit_sub, (t_destr_func)sub_destr);
	exit(exit_code);
}
