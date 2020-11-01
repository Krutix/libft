/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:48:53 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 01:27:26 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdef.h"

t_bool	ft_isdigit(int c)
{
	return ('0' <= (unsigned)c && (unsigned)c <= '9');
}
