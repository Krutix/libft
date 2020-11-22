/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutix <krutix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 20:32:58 by fdiego            #+#    #+#             */
/*   Updated: 2020/11/19 22:43:34 by krutix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

#include "ftdef.h"

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	t_data			item;
}					t_btree;

#endif
