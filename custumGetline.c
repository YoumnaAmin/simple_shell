#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BSIZE 1024

/**
 * customGetline - read a line from input stream
 * @line: pointer to a space where the stdin read will be saved
 * @bufferSize: current size of buffer (must be given as 0 initially)
 *
 * Return: Number of Characters Read
 *
 */
int customGetline(char **line, size_t *bufferSize, FILE *stream)
{
	static char *buff;
	static size_t size;
	size_t len = 0, i = 0;
	char *temp = NULL;

	if (*bufferSize == 0)
		size = BSIZE;
	if (*line == NULL)
	{
		buff = malloc(sizeof(char) * size);
		if (buff == NULL)
	{
		perror("Memory Error");
		return (-1);
	}
		*line = buff;
	}
	buff = memset(buff, '\0', size);
	do {
		ssize_t r = fread(buff + len, 1, BSIZE, stream);

		if (r >= 0)
		{
			i = len;
			len += r;
		}
		if (r == 0 || r == -1)
		{
			return (-1);
		}
		if (len >= size)
		{
			size *= 2;
			buff = realloc(buff, size);
			if (temp == NULL)
			{
			perror("Memory Error");
			return (-1);
		}
		buff = temp;
		}
		for (; i < len; i++)
		{
			if (buff[i] == '\n')
			{
				*line = buff;
				*bufferSize = size;
				return (len);
			}
		}
	} while (1);
	return (len);
}
