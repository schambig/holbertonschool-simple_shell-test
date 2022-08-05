#include "main.h"

/**
 * hsh_execute - Fork process and replace the child with a new program
 * @arguments: String of arguments (tokens)
 * @argv: Array of arguments
 * @exit_status: Exit status
 * Return: Always 1 (success).
 */
int hsh_execute(char **arguments, char **argv, int *exit_status)
{
	pid_t pid;
	int status; /* this will be used with waitpid syscall */
	char *new_arguments;

	/* check if PATH exists and can be accessed, also tokenize PATH*/
	new_arguments = validate_input(arguments, argv);
	if (strcmp(new_arguments, "Fail access") == 0)
		return (1);

	pid = fork(); /* create a duplicate process (child)*/
	if (pid == 0) /* child process */
	{
		/* execute a completely new program instead of the child */
		if (execve(new_arguments, arguments, environ) == -1)
		{
			perror("execve fail");
			/*free(new_arguments);*/
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) /* check if fork fails */
	{
		perror("Error forking");
		free(new_arguments);
		return (1);
	}
	else /* parent process */
	{
		/* this is equivalent to wait(&status) */
		waitpid(-1, &status, 0);
		/* check if the child terminated normally */
		if (WIFEXITED(status))
			/* return the exit status of the child */
			*exit_status = WEXITSTATUS(status);
		/* evaluate first element of first token */
		if (arguments[0][0] != '/' && arguments[0][0] != '.')
			free(new_arguments);
		return (1);
	}
	return (1);
}
