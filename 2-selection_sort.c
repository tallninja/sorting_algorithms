#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *@array: point to first element in array
 *@size: size of the array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t cont = 0, min = 0, i = 0;
	int tmp = 0;

	if (!array || !size)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		tmp = 0;
		for (cont = i + 1; cont < size; cont++)
		{
			if (array[cont] < array[i] && array[min] > array[cont])
				min = cont;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
