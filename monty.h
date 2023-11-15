#ifndef _MONTY_H_
#define _MONTY_H_

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	 int i;
	 struct stack_s *prev;
	 struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct data_s - lists of arg and number of line of the op code
 * @arg: the argument of the opcode
 * @line: the line number
 * @file: the file descriptor
 */
typedef struct data_s
{
	char *arg;
	unsigned int line;
	ssize_t file;
} data_t;
extern data_t data;

void readf(const char *filename);
void execute(char *opcode, char *arg, unsigned int counter);

#endif
