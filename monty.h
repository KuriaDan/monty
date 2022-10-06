#ifndef MONTY_H
#define MONTY_H
/* macros to enable dprintf */
#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
	int n;
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
  * struct global_var_s - struct for globally used variables
  * @file: The monty file being read
  * @lineNum: The current line number being read
  * @stack: The stack being used
  * @line: The current line being read
  * @isStack: is it a stack?
  */

typedef struct global_var_s
{
	FILE *file;
	unsigned int lineNum;
	stack_t *stack;
	char *line;
	char isStack;
} global_var_t;

/* Making the global variables available to every file */
extern global_var_t gvar;

void _printerr(char *c);
void openfile(char *name);
void process(void);
void push(char *num);
void pall(stack_t **stack, unsigned int lineNum);
void runopcode(char *opcode, unsigned int lineNum);
void cleanup(void);
void checkNum(char *str);
void pint(stack_t **stack, unsigned int lineNum);
void pop(stack_t **stack, unsigned int lineNum);
void swap(stack_t **stack, unsigned int l);
void pushInt(int n);
void add(stack_t **stack, unsigned int l);
void nop(stack_t **stack, unsigned int l);

#endif
