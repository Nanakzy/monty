#include "monty.h"
#include <stdio.h>

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	unsigned int line_number = 0;
	char *line = NULL;
	size_t len = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(1);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(1);
	}
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
	}

	free(line);
	fclose(file);

	return (0);
}
