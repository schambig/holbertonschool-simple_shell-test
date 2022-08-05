#include "main.h"

/**
 * hsh_env - Function that print enviromental
 * @args: arguments
 * @input_stdin: input of stdin
 * @exit_status: exit status
 * Return: Always 1 (success)
 */
int hsh_env(char **args, char *input_stdin, int *exit_status)
{
	int i = 0;

	(void)args;
	(void)input_stdin;
	(void)exit_status;


	if (environ[i] == NULL)
	{
		printf("%s", "The built in env is empty");
		return (1);
	}
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

	return (1);
}
