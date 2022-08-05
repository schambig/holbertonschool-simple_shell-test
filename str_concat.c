#include "main.h"

/**
 * str_concat - Concatenate two strings
 * @s1: String 1
 * @s2: String 1
 * Return: Pointer to the concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	char *s;
	unsigned int i;
	unsigned int j;
	unsigned int k;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		continue;

	for (j = 0; s2[j] != '\0'; j++)
		continue;

	j = j + 1;

	s = malloc((i + j) * sizeof(char));

	if (s == NULL)
		return (0);

	for (k = 0; k < (i + j) ; k++)
	{
		if (k < i)
			s[k] = s1[k];
		if (k >= i)
			s[k] = s2[k - i];
	}
	return (s);
}
