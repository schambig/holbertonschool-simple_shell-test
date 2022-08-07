#include "main.h"

/**
 * hsh_cd - Change directory
 * @args: Array of tokens
 * @input_stdin: Input from stdin
 * @exit_status: Exit status
 * Return: 1 (success)
 */
int hsh_cd(char **args, char *input_stdin, int *exit_status)
{
	int stat; /* to check chdir() return value */
	char s[128]; /* size of the string s */

	/* get the current working directory, and save it in s */
	getcwd(s, sizeof(s));

	(void)input_stdin;
	(void)exit_status;

	/* we recieve cd without any other argument */
	if (args[1] == NULL)
		/* change to home directory */
		stat = chdir(getenv("HOME"));
	/* we recieve cd - */
	else if (strcmp(args[1], "-") == 0)
		/* change to previous directory */
		stat = chdir(getenv("OLDPWD"));
	/* we recieve cd ~ */
	else if (strcmp(args[1], "~") == 0)
		/* change to home directory */
		stat = chdir(getenv("HOME"));
	else /* change to any path given (absolute or relative) */
		stat = chdir(args[1]);

	/* check if any chdir() syscall had an error */
	if (stat == -1)
		perror("cd had an error");

	/* add the variable OLDPWD to the environment with the value of s */
	/* 1 --> if OLDPWD already exist its value is chaged to s (overwrite) */
	setenv("OLDPWD", s, 1);
	/* ...with the value get from getcwd() */
	/* ...is changed to the value get from getcwd() */
	setenv("PWD", getcwd(s, sizeof(s)), 1);
	return (1);
}
