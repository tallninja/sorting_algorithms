#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the bubble sort algorithm
 * @array: array
 * @size: size of the array
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, temp = 0;

	if (!array || !size)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i; j++)
		{
			if (j == size - 1)
				break;
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
