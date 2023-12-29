#include "monty.h"

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	initStack(&stack);

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		if (read > 0 && line[read - 1] == '\n')
		{
			line[read - 1] = '\0';

			parse_instruction(line, &stack, line_number);
		}
	}

	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
