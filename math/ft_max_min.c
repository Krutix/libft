/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 22:46:28 by fdiego            #+#    #+#             */
/*   Updated: 2021/01/28 17:41:10 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftdef.h>

t_llint		ft_maxi(t_llint a1, t_llint a2)
{
	return (a1 < a2 ? a2 : a1);
}

t_llint		ft_mini(t_llint a1, t_llint a2)
{
	return (a1 < a2 ? a1 : a2);
}

t_ullint	ft_maxu(t_ullint a1, t_ullint a2)
{
	return (a1 < a2 ? a2 : a1);
}

t_ullint	ft_minu(t_ullint a1, t_ullint a2)
{
	return (a1 < a2 ? a1 : a2);
}
