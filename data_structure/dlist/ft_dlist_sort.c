/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiego <fdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:16:16 by fdiego            #+#    #+#             */
/*   Updated: 2021/01/28 17:37:14 by fdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <stddef.h>

void    ft_dlist_insert(t_dlist *position, t_dlist *node)
{
    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;
    node->prev = position;
    node->next = position->next;
    position->next = node;
}

void    ft_dlist_sort(t_dlist **begin_list, void(*upd)(void*, void*), void *addition_data, int(*cmp)())
{
    t_dlist *sorted;
    t_dlist *next;
    t_dlist *t;

    sorted = *begin_list;
    while (sorted)
    {
        next = sorted->next;
        if (upd)
            upd(sorted->data, addition_data);
        t = sorted->prev;
        while (t && cmp(t->data, sorted->data) > 0)
            t = t->prev;
        if (t != sorted->prev)
        {
            if (t)
                ft_dlist_insert(t, sorted);
            else
            {
                if (sorted->prev)
                    sorted->prev->next = sorted->next;
                if (sorted->next)
                    sorted->next->prev = sorted->prev;
                sorted->prev = NULL;
                ft_dlist_push_front(begin_list, sorted);
            }
        }
        sorted = next;
    }
}
