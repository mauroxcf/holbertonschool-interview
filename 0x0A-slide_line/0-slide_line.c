#include "slide_line.h"
/**
 * slide_line - Reproduce the 2048 game(NSFW !!)
 * @line: Points to an array of integers containing
 * @size: Elements
 * @direction: Line Direction
 * Return: 1 on success, or 0 upon on failure
 */

int slide_line(int *line, size_t size, int direction)
{
	int index = 0, index_2 = 0, size_int = size, tmp = 0;

	if (line == NULL || (direction != 0 && direction != 1))
		return (0);

	if (direction == 0)
	{
		for (index = 0; index < size_int; index++)
		{
			if (line[index] == line[index + 1] && line[index] != 0)
			{
				line[index_2++] = line[index] + line[index + 1],
				index++;
				line[index_2] = 0;
			}
			else if (line[index] != 0)
			{
				if (tmp == line[index])
				{
					line[--index_2] = tmp * 2;
					index_2++;
					tmp = 0;
				}
				else
					line[index_2++] = line[index], tmp =
					line[index];
			}
		}
		for (index = index_2; index < size_int; index++)
			line[index] = 0;
	}
	else
	{
		index_2 = size - 1;

		for (index = size_int - 1; index > -1; index--)
		{
			if (line[index] == line[index - 1] && line[index] != 0)
			{
				line[index_2--] = line[index] +
				line[index - 1], index--;
				line[index_2] = 0;
			}
			else if (line[index] != 0)
			{
				if (tmp == line[index])
				{
					line[++index_2] = tmp * 2;
					index_2--;
					tmp = 0;
				}
				else
					line[index_2--] = line[index],
					tmp = line[index];
			}
		}
		for (index = index_2; index > -1; index--)
			line[index] = 0;
	}
	return (1);
}
