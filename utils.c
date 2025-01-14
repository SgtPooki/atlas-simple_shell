#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * _getenv()- gets a specific environment variable
 * @name: name of variable desired
 *
 * Return: the value on success, NULL on fail
 */

char *_getenv(const char *name)
{
	int i, j;
	int status;

	for (i = 0; environ[i] != NULL; i++)
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				status = 0;
				break;
			}
		}
		if (status)
		{
			return (&environ[i][j + 1]);
		}
	}
	return (NULL);
}

/**
 * free_vector()- frees an array of characters
 * @vector: the array in question
 *
 * Return: no return
 */

void free_vector(char **vector)
{
	int i;

	i = 0;
	while (vector[i] != NULL)
	{
		free(vector[i]);
		i++;
	}
	free(vector);
}

/**
 * print_env()- prints out the environment
 *
 * Return: no return
 */

void print_env(void)
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}

}
