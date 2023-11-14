#include "monty.h"
/**
 * readf - reads a file and parses it
 * @fd: pointer to the file descriptor of the file to read
 */
void readf(const char *filename)
{
	char *text = NULL;
	size_t size = 0;
	ssize_t fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprint
	}
}
