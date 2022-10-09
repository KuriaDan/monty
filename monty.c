#include "monty.h"

global_var_t gvar;
/**
  * main - Main function the program enters
  * @argc: Number of arguments passed to the program
  * @argv: pointer to pointers of arguments passed
  * Return: 0 on success
  */
int main(int argc, char **argv)
{
	gvar.stack = NULL;
	gvar.line = NULL;
	gvar.isStack = 1;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	openfile(argv[1]);
	process();
	cleanup();
	return (0);
}
/**
  * openfile - opens the moty file passed by user
  * @name - name of the file
  */
void openfile(char *name)
{
	FILE *file;

	file = fopen(name, "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}

	gvar.file = file;
}
/**
  * process processes the monty file line by line
  */
void process(void)
{
	ssize_t read;
	size_t len = 0;
	char *opcode;

	while ((read = getline(&gvar.line, &len, gvar.file)) != -1)
	{
		gvar.lineNum++;
		opcode = strtok(gvar.line, " \t\n");
		if (!opcode || opcode[0] == '#')
			continue;
		if (strcmp(opcode, "push") == 0)
			push(strtok(NULL, " \t\n"));
		else
			runopcode(opcode, gvar.lineNum);
	}
}
/**
  * runopcode - Runs a given opcode unless it's invalid
  * @opcode: opcode to run
  *@lineNum: line number the opcode is on
  */
void runopcode(char *opcode, unsigned int lineNum)
{
	unsigned int i;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"pop", pop},
		{"add", add},
		{"pint", pint},
		{"swap", swap},
		{"nop", nop},
		{"pchar", pchar},
		{"rotl", rotl},
		{"rotr", rotr},
		{"pstr", pstr},
		{NULL, NULL}
	};
	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(&gvar.stack, lineNum);
			return;
		}
	}

	dprintf(STDERR_FILENO, "l%u: unknown instruction %s\n", lineNum, opcode);
	cleanup();
	exit(EXIT_FAILURE);
}
/**
  * cleanup - function to free up memory
  * return: nothing
  */
void cleanup(void)
{
	stack_t *item;

	while (gvar.stack)
	{
		item = gvar.stack->next;
		free(gvar.stack);
		gvar.stack = item;
	}
	free(gvar.line);
	fclose(gvar.file);
}
