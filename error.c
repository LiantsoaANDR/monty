#include "monty.h"
/**
 * err1 - prints an error msg on the stderr then exit
 * @msg: the msg to print
 * @line_number: where the wrong input on the file
 */
void err1(char *msg, unsigned int line_number)
{
	dprintf(STDERR_FILENO, msg, line_number);
	free_stack(*stack);
	free(data.line);
	close(data.file);
	exit(EXIT_FAILURE);
}
