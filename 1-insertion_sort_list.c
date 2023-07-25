#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers ascending order
 *
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		insertion_point = current->prev;

		while (insertion_point != NULL && current->n < insertion_point->n)
		{
			tmp = current->next;

			if (tmp != NULL)
				tmp->prev = insertion_point;
			insertion_point->next = tmp;

			current->next = insertion_point;
			current->prev = insertion_point->prev;
			insertion_point->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			insertion_point = current->prev;
			print_list(*list);
		}

		current = current->next;
	}
}
