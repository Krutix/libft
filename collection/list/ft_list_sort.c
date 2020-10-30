#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*prev;
	t_list	*buff;
	t_list	*next;
	int		is_sorted;

	is_sorted = 0;
	while (!is_sorted)
	{
		buff = *begin_list;
		prev = 0;
		is_sorted = 1;
		while (buff && buff->next)
		{
			next = buff->next;
			if (cmp(buff->data, buff->next->data) > 0)
			{
				next = buff->next->next;
				if (prev)
					prev->next = buff->next;
				else
					*begin_list = buff->next;
				buff->next->next = buff;
				buff->next = next;
				is_sorted = 0;
			}
			prev = buff;
			buff = next;
		}
	}
}