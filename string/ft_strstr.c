/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:55:36 by fdiego            #+#    #+#             */
/*   Updated: 2020/10/01 14:52:21 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	isr;

	i = 0;
	isr = 0;
	if (*to_find == '\0')
		return (str);
	while (str[isr])
	{
		if (str[isr] == to_find[0])
		{
			while (str[isr + i] == to_find[i])
			{
				i++;
				if (to_find[i] == '\0')
					return (str + isr);
				else if (str[isr + i] == '\0')
					return ((char*)0);
			}
			i = 0;
		}
		isr++;
	}
	return (0);
}
