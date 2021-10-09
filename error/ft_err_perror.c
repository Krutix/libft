/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_perror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 06:59:41 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/09 07:00:07 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_error.h>
#include <ft_io.h>

char const	*ft_strerr(t_ft_err err)
{
	return ((char const *)(0 \
	+ (err == ft_err_ok) * (intptr_t)"ok" \
	+ (err == ft_err_fail) * (intptr_t)"fail" \
	+ (err == ft_err_bad_arg) * (intptr_t)"bad argument" \
	+ (err == ft_err_toomanyargs) * (intptr_t)"too many arguments" \
	+ (err == ft_err_bad_alloc) * (intptr_t)"memory allocation failed" \
	+ (err == ft_err_overflow) * (intptr_t)"overflow" \
	+ (err == ft_err_underflow) * (intptr_t)"underflow" \
	+ (err == ft_err_unclosedquotes) * (intptr_t)"unclosed quotes" \
	+ (err == ft_err_bad_access) * (intptr_t)"bad access rights" \
	+ (err == ft_err_isadir) * (intptr_t)"is a directory" \
	+ (err == ft_err_bad_syntax) * (intptr_t)"syntax error" \
	+ (err == ft_err_bad_cmd) * (intptr_t)"command not found" \
	+ (err == ft_err_bad_substitution) * (intptr_t)"bad substitution" \
	));
}

t_ft_err	ft_err_perror(char const *msg, t_ft_err err)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(ft_strerr(err), STDERR_FILENO);
	ft_putendl_fd("", STDERR_FILENO);
	return (err);
}
