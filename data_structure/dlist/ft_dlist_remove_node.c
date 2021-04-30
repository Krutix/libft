#include "ft_dlist.h"
#include "stdlib.h"

void	ft_dlist_remove_node(t_dlist **begin_list, \
			t_dlist *node, void (*free_fct)(void*))
{
	if (free_fct)
		free_fct(node->data);
	if (node->prev)
		node->prev->next = node->next;
	else
		*begin_list = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);
}
