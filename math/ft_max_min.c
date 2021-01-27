/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 22:46:28 by fdiego            #+#    #+#             */
/*   Updated: 2020/12/31 22:46:29 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftdef.h>

llint	ft_maxi(llint a1, llint a2)
{
	return (a1 < a2 ? a2 : a1);
}

llint	ft_mini(llint a1, llint a2)
{
	return (a1 < a2 ? a1 : a2);
}

ullint	ft_maxu(ullint a1, ullint a2)
{
	return (a1 < a2 ? a2 : a1);
}

ullint	ft_minu(ullint a1, ullint a2)
{
	return (a1 < a2 ? a1 : a2);
}