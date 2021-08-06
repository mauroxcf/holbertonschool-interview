#include "binary_trees.h"


void recursive_insert(heap_t **parent, heap_t *new);
static size_t leafs_h(const heap_t *tree, char *balance);

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value to store in the node to be inserted
 *
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (!value)
		return (NULL);

	new = binary_tree_node(NULL, value);
	if (!new)
		return (NULL);

	if (*root == NULL)
		*root = new;
	else
		recursive_insert(root, new);
	return (new);
}

/**
 * recursive_insert - inserts node in Max Heap ordering
 *
 * @parent: is a double pointer to the root parent of the Heap
 * @new: a pointer of the node to insert
 *
 * Return: Nothing
 */
void recursive_insert(heap_t **parent, heap_t *new)
{
	heap_t *current_p;
	char b_left = 'B';
	char b_right = 'B';

	current_p = *parent;
	if (current_p->n >= new->n)
	{
		if (!(current_p->left))
		{
			current_p->left = new;
			new->parent = current_p;
		}
		else if (!(current_p->right))
		{
			current_p->right = new;
			new->parent = current_p;
		}
		else if (leafs_h(current_p->left, &b_left) ==
			leafs_h(current_p->right, &b_right) &&
			(b_left == b_right))
			recursive_insert(&(current_p->left), new);
		else if (b_left == 'D')
			recursive_insert(&(current_p->left), new);
		else
			recursive_insert(&(current_p->right), new);
	}
	else
	{
		new->parent = current_p->parent;
		new->left = current_p->left;
		new->right = current_p->right;
		if (new->left)
			new->left->parent = new;
		if (new->right)
			new->right->parent = new;
		*parent = new;
		current_p->parent = NULL,
		current_p->left = NULL;
		current_p->right = NULL;
		/* previous parent reallocation: */
		recursive_insert(parent, current_p);
	}
}

/**
 * leafs_h - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 * @balance: a char pointer storing 'B' for balanced or 'D' debalanced
 *
 * Return: The height of the tree starting at @node
 */
static size_t leafs_h(const heap_t *tree, char *balance)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + leafs_h(tree->left, balance) : 0;
	height_r = tree->right ? 1 + leafs_h(tree->right, balance) : 0;
	*balance = (height_l == height_r ? 'B' : 'D');
	return (height_l > height_r ? height_l : height_r);
}
