/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:53:48 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/01 21:48:40 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		ft_sort_str_tab(char **tab, int (*cmp)(char *, char *))
{
	int len;

	len = 0;
	while (tab[len])
		len++;
	sort(tab, len, cmp);
}
