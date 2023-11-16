#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @i: integer
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
	char *line;
	ssize_t file;
} data_t;
extern data_t data;


void readf(const char *filename);
void exec(ssize_t fd, unsigned int l, stack_t **stack);

/* opcode functions */
void err1(char *msg, unsigned int line_number,stack_t **stack);
void pushf(stack_t **stack, unsigned int nbr);

/* node functions */
void add_node(stack_t **head, int i);
void free_stack(stack_t *head);


#endif
