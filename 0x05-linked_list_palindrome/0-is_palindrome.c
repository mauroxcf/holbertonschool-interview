#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a
 *                  palindrome
 * @n: the unsigned int to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	int nidx, pivot, i;
	unsigned long tmp, left, right;

	if (n < 10)
		return (1);

	tmp = n;
	left = 0;
	right = 1;
	nidx = 0;

	for (nidx = 0; tmp; nidx++)
	{
		tmp = tmp / 10;
		if (left)
			left = left * 10;
		else
			left++;
	}

	pivot = nidx / 2;
	for (i = 0; i < pivot; i++)
	{
		if ((n / left % 10) != (n / right % 10))
			return (0);
		left = left / 10;
		right = right * 10;
	}

	return (1);
}
