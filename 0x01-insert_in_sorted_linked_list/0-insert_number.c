#include "lists.h"

/**
 * insert_node - insert a node in a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *current, *temp;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	if (head == NULL || *head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	temp = *head;
	current = temp;

	if (current->n >= number)
	{
		new_node->next = temp;
		*head = new_node;
		return (new_node);
	}

	while (temp)
	{
		if (temp->n >= new_node->n)
		{
			new_node->next = temp;
			current->next = new_node;
			return (new_node);
		}
		current = temp;
		temp = temp->next;
	}

	current->next = new_node;
	return (new_node);
}
