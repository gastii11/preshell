#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * split_line - splits a string into an array of words
 * @line: the input string to split
 * Return: an array of words (char **)
 */

char **split_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	/*Verificamos si la memoria fue correctamente asignada*/
	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(1);
	}

	/*Usamos strtok para dividir la línea en tokens*/
	token = strtok(line, " \t\r\n\a");

	/*Continuamos extrayendo tokens hasta que no haya más*/
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		/*Si hemos alcanzado el tamaño del buffer, redimensionamos el array*/
		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "allocation error\n");
				exit(1);
			}
		}

		token = strtok(NULL, " \t\r\n\a"); /*Extraemos el siguiente token*/
	}

	/*Terminamos la lista de tokens con NULL*/
	tokens[position] = NULL;
	return (tokens);
}
