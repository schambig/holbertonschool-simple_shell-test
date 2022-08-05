#include "main.h"

/**
 * hsh_cd - change directory
 * @args: argument array
 * @input_stdin: input of stdin
 * @exit_status: exit status
 * Return: 1 (success)
 */
int hsh_cd(char **args, char *input_stdin, int *exit_status)
{
	int stat;
	char s[128];

	getcwd(s, sizeof(s));

	(void)input_stdin;
	(void)exit_status;

	if (args[1] == NULL)
		stat = chdir(getenv("HOME"));
	else if (strcmp(args[1], "-") == 0)
		stat = chdir(getenv("OLDPWD"));
	else if (strcmp(args[1], "~") == 0)
		stat = chdir(getenv("HOME"));
	else
		stat = chdir(args[1]);

	if (stat == -1)
		perror("cd had an error");

	setenv("OLDPWD", s, 1);
	setenv("PWD", getcwd(s, sizeof(s)), 1);
	return (1);
}
