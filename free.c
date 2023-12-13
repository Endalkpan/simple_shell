#include "main.h"
#include <stdarg.h>

/**
 * free_char1 - frees multple arguments of char *
 * @n: number of arguments
 */

void free_char1(const unsigned int n, ...)
{
	va_list all;
	unsigned int i;

	if (n == 0)
		return;

	va_start(all, n);

	for (i = 0; i < n; i++)
	{
		free(va_arg(all, char *));
	}

	va_end(all);
}

/**
 * free_list - frees a list
 * @head: the list
 */

void free_list(list_t **head)
{
	list_t *tmp;

	if (head == NULL || *head == NULL)
		return;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->path);
		free(tmp);
	}

	*head = NULL;
}

/**
 * free_grid - frees a 2 dimensional grid
 *	previously allocated by alloc_grid
 * @grid: the grid
 */

void free_grid(char **grid)
{
	int i = 0;

	for (i = 0; grid[i] ; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

/**
 * free_grid_half - frees the inside of a 2D Arr
 * @grid: the array to free
 */

void free_grid_half(char **grid)
{
	int i = 0;

	for (i = 0; grid[i] ; i++)
	{
		free(grid[i]);
	}
}
