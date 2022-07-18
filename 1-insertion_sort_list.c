#include "sort.h"

/**
 * swap_nodes - function that swap nodes in doubly linked list
 *@current: point current of the doubly linked list
 *@flag: is one if swap is in the head of the list
 * Return: pointer to the current point
 */
listint_t *swap_nodes(listint_t *current, int *flag)
{
	listint_t *tmp = current->next;

	tmp->prev = NULL;
	if (current->prev != NULL)
	{
		tmp->prev = current->prev;
		tmp->prev->next = tmp;
	}
	else if (current->prev == NULL)
		*flag = 1;

	current->prev = tmp;
	current->next = tmp->next;
	tmp->next = current;
	if (current->next != NULL)
		current->next->prev = current;

	return (tmp);
}

/**
 * insertion_sort_list - function that swaps nodes
 *@list: pointer to list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	int flag;

	if (!list || !*list)
		return;

	current = *list;
	while (current->next)
	{
		flag = 0;
		if (current->n > current->next->n)
		{
			current = swap_nodes(current, &flag);
			if (flag == 1)
				*list = current;
			print_list(*list);
			while (current->prev != NULL && current->prev->n > current->n)
			{
				swap_nodes(current->prev, &flag);
				if (flag == 1)
					*list = current;
				print_list(*list);
			}
		}
		current = current->next;
	}
}
