#include "binary_trees.h"

/**
* binary_tree_node - function to create a tree
* @parent: node parent
* @value: value of the new node
* Return: pointer to new node
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *temp = NULL;

	if (!value)
		return (NULL);

	temp = malloc(sizeof(binary_tree_t));
		if (temp == NULL)
			return (NULL);

	temp->n = value;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = parent;

		return (temp);
}
