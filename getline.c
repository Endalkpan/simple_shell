#include "main.h"

/**
 * _getline - Read a line from the file or stream
 * @line: the line read
 * @size: the size of the line
 * @source: the stream to read from
 * Return: number of characters read
 */

ssize_t _getline(char **line, size_t *size, FILE *source)
{
	size_t read_count = 0;
	int next_c;

	if (source == NULL)
	{
		return (-1);
	}

	if (*line == NULL || *size == 0)
	{
		*size = 512;
		*line = malloc(*size);
		if (*line == NULL)
			return (-1);
	}

	while ((read_count < *size - 1) && (next_c = fgetc(source)) != EOF)
	{
		(*line)[read_count++] = (char)next_c;
		if (next_c == '\n')
			break;
	}

	(*line)[read_count] = '\0';

	if (read_count == 0 && next_c == EOF)
		return (-1);

	if (read_count == *size - 1 && next_c != '\n')
	{
		*size *= 2;
		*line = realloc(*line, *size);
		if (*line == NULL)
		{
			return (-1);
		}
	}

	return (read_count);
}
