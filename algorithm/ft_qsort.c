#include "ftdef.h"
#include "ft_math.h"
#include "stdio.h"

static void	*partition(void *begin, void *end, size_t size_of_cell, t_bool (*lower)())
{
	void	*pivot;
	void	*i;

	pivot = end;
	i = begin;
	for (void *j = begin; j < end; j += size_of_cell)
	{
		if (lower(j, pivot))
		{
			ft_swap_n(i, j, size_of_cell);
			i += size_of_cell;
		}
	}
	ft_swap_n(i, end, size_of_cell);
	return (i);
}

void	ft_qsort(void *begin, void *end, size_t size_of_cell, t_bool (*lower)())
{
	void	*stack[(end - begin) / size_of_cell + 1];
	void	*p;
	int		top;

	top = -1;
	stack[++top] = begin;
	stack[++top] = end - size_of_cell;
	while (top > 0)
	{
		end = stack[top--];
		begin = stack[top--];
		p = partition(begin, end, size_of_cell, lower);
		if (p - size_of_cell > begin)
		{
			stack[++top] = begin;
			stack[++top] = p - size_of_cell;
		}
		if (p + size_of_cell < end)
		{
			stack[++top] = p + size_of_cell;
			stack[++top] = begin;
		}
	}
}
