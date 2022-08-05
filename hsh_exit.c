#include "main.h"

/**
 * hsh_exit - Function exit built in
 * @args: arguments
 * @input_stdin: input of stdin
 * @exit_status: exit status
 * Return: Exit success
 */
int hsh_exit(char **args, char *input_stdin, int *exit_status)
{
	int output_exit = 0;

	(void)args;
	(void)input_stdin;
	(void)exit_status;

	if (args[1] == NULL)
	{
		free(args);
		free(input_stdin);
		exit(*exit_status);
	}
	if (args[2] != NULL)
	{
		fprintf(stderr, "exit: too many arguments\n");
		return (0);
	}
	output_exit = atoi(args[1]);
	free(args);
	free(input_stdin);
	exit(output_exit);
}
