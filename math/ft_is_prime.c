/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:01:51 by fdiego            #+#    #+#             */
/*   Updated: 2020/09/15 14:01:53 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_sqrt_prime(unsigned int nb)
{
	unsigned int i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

int				ft_is_prime(int nb)
{
	unsigned int i;
	unsigned int sqrt;

	if (nb <= 1)
		return (0);
	i = 5;
	if ((nb % 2 == 0 || nb % 3 == 0) && nb != 2 && nb != 3)
		return (0);
	sqrt = ft_sqrt_prime((unsigned int)nb);
	while (i < sqrt)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
