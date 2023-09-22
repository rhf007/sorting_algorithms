#include "sort.h"

/**
 * insertion_sort_list -  sorts doubly-linked list using insertion sort
 * @list: pointer to the list
 */
void insertion_sort_list(listint_t **list)
{
	int i, j, key;
	listint_t *current, *prv, *tmp;

	if (list == NULL || *list == NULL)
		return;
	current = *list;
	while (current = current->next)
	{
		tmp = current;
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			prv = tmp->prev;
			/**
			 * do i have a next?
			 * yes: make it point to my previous
			 */
			if (tmp->next)
				tmp->next->prev = prv;

			/**
			 * does my previous have another previous before it?
			 * yes: make it point to my next
			 */
			if (prv->prev)
				prv->prev->next = tmp->next;

			/**
			 * no: then the previous of my previous is null which means
			 * the list pointer/head should move to point to me, so that i'm the head
			 */
			else
				*list = tmp;

			/**
			 * now that im done checking my boundaries, make my previous point to my
			 * next & make my prev pointer point to the same thing my previous' prev pointer
			 * is pointing to
			 * make my next point to previous (hence the swap, my previous now comes after me)
			 * make my previous prev point to me
			 */
			prev->next = tmp->next;
			tmp->prev = prv->prev;
			tmp->next = prv;
			prv->prev = tmp;
			print_list(*list);
		}
	}
}
