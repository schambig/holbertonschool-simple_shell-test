#include "main.h"

/**
 * hsh_execute_builtins - Choose from an array of builtin functions
 * @args: String of arguments (tokens)
 * @input_stdin: String from input
 * @argv: Array of arguments
 * @exit_status: Exit status
 * Return: Status to stay or exit the main loop, 1 or 0
 */
int hsh_execute_builtins(char **args, char *input_stdin,
			 char **argv, int *exit_status)
{
	int i = 0;

	/* builtin functions array of type 'structure choose_builtin' (see main.h) */
	choose_builtins_t options[] = {
		{"exit", hsh_exit},
		{"env", hsh_env},
		{"cd", hsh_cd},
		{"setenv", hsh_setenv},
		{"unsetenv", hsh_unsetenv},
		{NULL, NULL}
	};

	while (options[i].name_builtin != NULL)
	{
		/* compare if args[0] matches the builtin function name */
		if (strcmp(options[i].name_builtin, args[0]) == 0)
		{
			/* return the pointer to function (2nd member of array) and execute it */
			return ((int)((*options[i].func_builtin)(args, input_stdin, exit_status)));
		}
		i++;
	}
	/* if no builtin function is encountered execute a process */
	return (hsh_execute(args, argv, exit_status));
}
