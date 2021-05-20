#include "ftst.h"
#include "ft_algorithm.h"

static t_bool cmp(int *a, int *b)
{
	return (*a < *b);
}

TEST(ft_qsort)
{
	int arr[] = {
		1, 5, 2, 7, 7, -1, 0
	};
	ft_qsort((void*)arr, (void*)(arr + 6), sizeof(int), &cmp);
	EQ(arr[0], -1);
	EQ(arr[1], 1);
	EQ(arr[2], 2);
	EQ(arr[3], 5);
	EQ(arr[4], 7);
	EQ(arr[5], 7);
}