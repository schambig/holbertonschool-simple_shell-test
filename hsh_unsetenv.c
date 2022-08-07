#include "main.h"

/**
 * hsh_unsetenv - Delete an environment variable from the environment
 * @args: Array of tokens from input
 * @input_stdin: Input from stdin
 * @exit_status: Exit status
 * Return: Return 1 if use a function, 0 otherwise.
 */
int hsh_unsetenv(char **args,  char *input_stdin, int *exit_status)
{
	int n_tokens = 0; /* to count how many tokens we recieve (sort of argc) */

	(void)input_stdin;
	(void)exit_status;

	/* get the number of tokens (sort of argc) */
	while (args[n_tokens] != NULL)
	{
		n_tokens++;
	}

	/* when we have 2 tokens */
	if (n_tokens == 2)
		/* delete the variable args[1] from the environment */
		unsetenv(args[1]);
	/* check if we recieve a number of tokens different than 2 */
	else if (n_tokens != 2)
		fprintf(stderr, "Try use \"unsetenv [KEY]\"\n");

	return (1);
}
