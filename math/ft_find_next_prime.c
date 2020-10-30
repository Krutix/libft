/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:47:42 by fdiego            #+#    #+#             */
/*   Updated: 2020/09/15 18:47:44 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	sqrt_prime(unsigned int nb)
{
	unsigned int i;

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}

int				is_prime(int nb)
{
	unsigned int i;
	unsigned int sqrt;

	if (nb <= 1)
		return (0);
	i = 3;
	if ((nb % 2 == 0 || nb % 3 == 0) && nb != 2 && nb != 3)
		return (0);
	sqrt = sqrt_prime((unsigned int)nb);
	while (i < sqrt)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int				ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (nb <= __INT_MAX__)
	{
		if (is_prime(nb))
			return (nb);
		nb++;
	}
	return (0);
}
