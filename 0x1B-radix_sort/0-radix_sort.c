#include "sort.h"
/**
 * max - max value
 * @t: array
 * @size: size
 * Return: max number of the array
 */
int max(int *t, int size)
{
	int i, max;

	for (max = t[0], i = 1; i < size; i++)
		if (t[i] > max)
			max = t[i];
	return (max);
}
/**
 * sort - sorting array
 * @t: array
 * @size:size
 * @num: num
 * Return - None
 */
void sort(int *t, int size, int num)
{
	int *output, i, count[10] = {0};

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	for (i = 0; i < size; i++)
		count[(t[i] / num) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(t[i] / num) % 10] - 1] = t[i];
		count[(t[i] / num) % 10]--;
	}

	for (i = 0; i < size; i++)
		t[i] = output[i];
	free(output);
}
/**
 * radix_sort - sort an array
 * @t:array to be sorted
 * @size:size of array
 * Return - None
 */
void radix_sort(int *t, size_t size)
{
	int num, m;

	if (size < 2)
		return;
	m = max(t, size);
	for (num = 1; m / num > 0; num *= 10)
	{
		sort(t, size, num);
		print_array(t, size);
	}
}
