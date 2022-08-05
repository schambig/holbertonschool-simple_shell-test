#include "main.h"

/**
 * hsh_unsetenv - Command of the simple shell eliminate a env var.
 * @args: argument array
 * @input_stdin: input of stdin
 * @exit_status: exit status
 * Return: Return 1 if use a function, 0 otherwise.
 */
int hsh_unsetenv(char **args,  char *input_stdin, int *exit_status)
{
	int n_tokens = 0;

	(void)input_stdin;
	(void)exit_status;

	while (args[n_tokens] != NULL)
	{
		n_tokens++;
	}

	if (n_tokens == 2)
		unsetenv(args[1]);
	else
		fprintf(stderr, "Try use \"unsetenv [KEY]\"\n");

	return (1);
}
