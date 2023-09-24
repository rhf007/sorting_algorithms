#include "sort.h"

/**
 * quick_sort - wrapper function tosort an array using quick sort
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

/**
 * my_actual_qs - the function that does all the sorting (not really hehe)
 * @array: array to be sorted
 * @low: lower bound of the array
 * @high: higher bound of the array
 * @length: array length
 */
void my_actual_qs(int *array, int low, int high, size_t length)
{
	int pvt_idx;

	if (low < high)
	{
		pvt_idx = partition(array, low, high, length);
		my_actual_qs(array, low, (pvt_idx - 1), length);
		my_actual_qs(array, (pvt_idx + 1), high, length);
	}
}

/**
 * partition - partition and sort array, for real
 * @array: array to be partitioned and sorted for real
 * @low: lower bound of the array
 * @high: higher bound of the array
 * @length: array length
 * Return: index of our pivot
 */
int partition(int *array, int low, int high, size_t length)
{
	int i, j, tmp, pvt_val = array[high];

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
