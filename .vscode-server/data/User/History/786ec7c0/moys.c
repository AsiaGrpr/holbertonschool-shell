#include "lists.h"
#include <stdio.h>

/**
 * print_list - function that prints all the elements of a list_t list
 * @h: pointer of each elements
 *
 * Return: number of nodes
 */

size_t print_list(const list_t *h)
{
	int c = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
			c++;
			h = h->next;
		}
		printf("[%d] %s\n", h->len, h->str);
		c++;
		h = h->next;
	}
	return (c);
}