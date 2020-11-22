/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:47:42 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/22 21:40:38 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int				ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (nb <= __INT_MAX__)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
	return (0);
}
