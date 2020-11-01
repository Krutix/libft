/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:53:07 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/02 01:27:09 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdef.h"

t_bool	ft_isprint(int c)
{
	return ((c & ~0x1f) && (unsigned)c < 127);
}
