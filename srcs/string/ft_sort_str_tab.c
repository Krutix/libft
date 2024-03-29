/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_str_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:53:48 by fdiego            #+#    #+#             */
/*   Updated: 2021/04/28 10:19:07 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static void	sort(char *argv[], int argc, int (*cmp)(char *, char *))
{
	int		ix;
	int		jx;
	char	*buff;

	ix = 0;
	jx = 0;
	while (ix < argc - 1)
	{
		jx = 0;
		while (jx < argc - ix - 1)
		{
			if (cmp(argv[jx], argv[jx + 1]) > 0)
			{
				buff = argv[jx + 1];
				argv[jx + 1] = argv[jx];
				argv[jx] = buff;
			}
			jx++;
		}
		ix++;
	}
}

void	ft_sort_str_tab(char **tab, int (*cmp)(char *, char *))
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	sort(tab, len, cmp);
}
