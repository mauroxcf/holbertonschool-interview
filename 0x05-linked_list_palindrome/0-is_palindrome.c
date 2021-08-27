#include "palindrome.h"

/**
 * is_palindrome - checks if a number is a palindrome
 * @n: the number to check
 * Return: 1 if n is palindrome 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	char num[50];
	int i, total_digits;

	for (i = 0; n; i++)
	{
		num[i] = n % 10;
		n = n / 10;
	}
	num[i] = '\0';

	total_digits = i;
	for (i = 0; i < (total_digits / 2); i++)

		if (num[i] != num[total_digits - 1 - i])
			return (0);

	return (1);
}
