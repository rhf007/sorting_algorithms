#include "sort.h"

/**
 * quick_sort - sort an array using quick sort]
 * @array: array to be sorted
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}

	my_actual_qs(array, 0, size - 1, size);
}

void my_actual_qs(int *array, size_t low, size_t high, size_t length)
{
	size_t pvt_idx;

	if (low < high)
	{
		pvt_idx = partition(array, low, high, length);
		my_actual_qs(array, low, (pvt_idx - 1), length);
		my_actual_qs(array, (pvt_idx + 1), high, length);
	}
}

size_t partition(int *array, size_t low, size_t high, size_t length)
{
	size_t i, j;
	int tmp, pvt_val = array[high];

	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pvt_val)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;

			if (i != j)
			{
				print_array(array, length);
			}

			tmp = 0;
			i++;
		}
	}

	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;

	if (i != j)
	{
		print_array(array, length);
	}
	return (i);

}
