#include "search_algos.h"


/**
 * advanced_binary - searches for a value in a sorted array of integers
 * using the Advanced Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return: the first index where value is located
 *         If value is not present in array or if array is NULL, -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t left, right;

	if (!array)
		return (-1);

	left = 0;
	right = size - 1;

	return (recursive_search(array, left, right, value));
}

/**
 * recursive_search - searches recursibly for a value
 * using the Advanced Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @left: left boundary of the sub array
 * @right: left boundary of the sub array
 * @value: is the value to search for
 *
 * Return: the first index where value is located
 *         If value is not present in array, -1
 */
int recursive_search(int *array, size_t left, size_t right, int value)
{
	size_t i, j;

	printf("Searching in array: ");
	for (j = left; j <= right; j++)
	{
		printf("%d", (int)array[j]);
		if (j < right)
			printf(", ");
		else
			printf("\n");
	}
	if (array[left] == value)
		return (left);

	i = (left + right) / 2;
	if (left >= right)
		return (-1);
	else if (array[i] < value)
		left = i + 1;
	else if (array[i] >= value)
		right = i;

	return (recursive_search(array, left, right, value));
}
