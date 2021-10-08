/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_perror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 00:09:56 by fdiego            #+#    #+#             */
/*   Updated: 2021/10/08 00:11:07 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_error.h>

t_ft_err   ft_err_perror(char const *msg, t_ft_err err)
{
    perror(msg);
    return (err);
}
