#include "ftdef.h"
#include "ft_algorithm.h"
#include "stdio.h"

static void	*partition(void *begin, void *end, \
				size_t size_of_cell, t_bool (*lower)())
{
	void	*pivot;
	void	*i;
	void	*j;

	pivot = end;
	i = begin;
	j = begin;
	while (j < end)
	{
		if (lower(j, pivot))
		{
			ft_swap_n(i, j, size_of_cell);
			i += size_of_cell;
		}
		j += size_of_cell;
	}
	ft_swap_n(i, end, size_of_cell);
	return (i);
}

void	ft_qsort(void *begin, void *end, size_t size_of_cell, t_bool (*lower)())
{
	void	*stack[(end - begin) / size_of_cell + 1];
	void	*p;
	size_t	top;

	top = 0;
	stack[top++] = begin;
	stack[top++] = end - size_of_cell;
	while (top > 0)
	{
		end = stack[--top];
		begin = stack[--top];
		p = partition(begin, end, size_of_cell, lower);
		if (p - size_of_cell > begin)
		{
			stack[top++] = begin;
			stack[top++] = p - size_of_cell;
		}
		if (p + size_of_cell < end)
		{
			stack[top++] = p + size_of_cell;
			stack[top++] = end;
		}
	}
}