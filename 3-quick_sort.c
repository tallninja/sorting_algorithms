#include "sort.h"

/**
 * partition - Lomuto partition scheme
 * @arr: array to be sorted
 * @low: is the low part of the partition
 * @high: is the high part of the partition
 * @size: number of elements in array
 * Return: Nothing
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1);
	int tmp = 0, j = 0;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				print_array(arr, size);
			}
		}
	}
	if (i + 1 != high)
	{
		tmp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = tmp;
		print_array(arr, size);
	}
	return (i + 1);
}

/**
 * quicksort - Lomuto partition scheme
 * @arr: array to be sorted
 * @low: is the low part of the partition
 * @high: is the high part of the partition
 * @size: number of elements in array
 * Return: Nothing
 */
void quicksort(int *arr, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(arr, low, high, size);

		quicksort(arr, low, pi - 1, size);
		quicksort(arr, pi + 1, high, size);
	}
}

/**
 * quick_sort - function that swaps element in array
 * @arr: array to be sorted
 * @size: number of elements in array
 * Return: Nothing
 */
void quick_sort(int *arr, size_t size)
{
	int low = 0;
	int high = size - 1;

	quicksort(arr, low, high, size);
}
