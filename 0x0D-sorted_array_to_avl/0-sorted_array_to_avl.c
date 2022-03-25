#include "binary_trees.h"

/**
 * to_avl_helper - Build an AVL tree from a sorted array
 * @array: Pointer to the array
 * @parent: Pointer to the parent
 * @start: The start index
 * @end: The end index
 *
 * Return: Pointer to the new AVL tree
 */
avl_t *to_avl_helper(int *array, avl_t *parent, int start, int end)
{
	int mid = (start + end) / 2;
	avl_t *new;

	if (!array || start > end)
		return (NULL);

	new = malloc(sizeof(avl_t));
	if (!new)
		return (NULL);

	new->n = array[mid];
	new->parent = parent;
	new->left = to_avl_helper(array, new, start, mid - 1);
	new->right = to_avl_helper(array, new, mid + 1, end);

	return (new);
}

/**
 * sorted_array_to_avl - Build an AVL tree from a sorted array
 * @array: Pointer to the array
 * @size: The size of the array
 *
 * Return: Pointer to the new AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (to_avl_helper(array, NULL, 0, size - 1));
}
