#include "main.h"

/**
 * hsh_setenv - Change or add and environment variable
 * @args: Array of tokens from input
 * @input_stdin: Input from stdin
 * @exit_status: Exit status
 * Return: Return 1 if use a function, 0 otherwise.
 */
int hsh_setenv(char **args,  char *input_stdin, int *exit_status)
{
	int n_tokens = 0; /* to count how many tokens we recieve (sort of argc) */

	(void)input_stdin;
	(void)exit_status;

	/* get the number of tokens (sort of argc)*/
	while (args[n_tokens] != NULL)
	{
		n_tokens++;
	}

	/* when we have 3 tokens */
	if (n_tokens == 3)
		/**
		 * now we are working with the array of tokens -> args[0] is setenv,
		 * add the variable args[1] to the environment with the value of args[2],
		 * 1 --> if args[1] already exist ist value is changed to args[2] (ovrwrite)
		 */
		setenv(args[1], args[2], 1);

	/* check if we recieve  a number of tokens different than 3 */
	else if (n_tokens != 3)
		fprintf(stderr, "Try use \"setenv [KEY] [VALUE]\"\n");
	/**
	 * else
	 *	fprintf(stderr, "Try use \"setenv [KEY] [VALUE]\"\n");
	 */
	return (1);
}
