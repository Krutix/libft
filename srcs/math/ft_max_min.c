/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 22:46:28 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 10:38:31 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftdef.h>

t_llint	ft_maxi(t_llint a1, t_llint a2)
{
	if (a1 < a2)
		return (a2);
	else
		return (a1);
}

t_llint	ft_mini(t_llint a1, t_llint a2)
{
	if (a1 < a2)
		return (a1);
	else
		return (a2);
}

t_ullint	ft_maxu(t_ullint a1, t_ullint a2)
{
	if (a1 < a2)
		return (a2);
	else
		return (a1);
}

t_ullint	ft_minu(t_ullint a1, t_ullint a2)
{
	if (a1 < a2)
		return (a1);
	else
		return (a2);
}
