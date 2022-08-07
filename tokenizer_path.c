#include "main.h"

#define BUFSIZE 64 /* constant buffer */
#define DELIM ":" /* delimiter to check */
/**
 * tokenizer_path - Split the environment variable PATH into an array of tokens
 * @input: Pointer to environment variable PATH
 * Return: Pointer to the array of tokens
 */
char **tokenizer_path(char *input)
{
	int buffer = BUFSIZE, newBuffer = 0, position = 0;
	char **tokens = NULL, *token = NULL;
	char **backup_tokens = NULL;

	/* allocate memory for the array of tokens */
	tokens = malloc(buffer * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	/* tokenize the PATH string, checking for DELIM and replace it with \0 */
	token = strtok(input, DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		/* reallocate the array of tokens if necessary*/
		if (position >= buffer)
		{
			newBuffer = BUFSIZE * 2;
			backup_tokens = tokens;
			tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
			if (tokens == NULL)
			{
				free(backup_tokens);
				free(tokens);
				fprintf(stderr, "memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		/* once memory reallocation, continue processing the PATH string */
		token = strtok(NULL, DELIM);
	}
	/* null terminate the array of tokens */
	tokens[position] = NULL;
	return (tokens);
}
