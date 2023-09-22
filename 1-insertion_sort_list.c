#include "sort.h"

/**
 * insertion_sort_list -  sorts doubly-linked list using insertion sort
 * @list: pointer to the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prv, *tmp;

	if (list == NULL || *list == NULL)
	{
		return;
	}

	current = *list;

	while ((current = current->next))
	{
		tmp = current;

		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			prv = tmp->prev;

			if (tmp->next)
			{
				tmp->next->prev = prv;
			}

			if (prv->prev)
			{
				prv->prev->next = tmp->next;
			}

			else
			{
				*list = tmp;
			}

			prv->next = tmp->next;
			tmp->prev = prv->prev;
			tmp->next = prv;
			prv->prev = tmp;
			print_list(*list);
		}
	}
}
