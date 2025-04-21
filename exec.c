#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
/**
 * execute_command - Busca y ejecuta un comando en el sistema
 * @command: Comando ingresado por el usuario
 * @args: Argumentos del comando
 * Return: Void
 */
void execute_command(char *command, char *args[])
{
	pid_t pid;
	int status;
	char *path, *path_copy, *token, full_path[256];

	if (strchr(command, '/'))
	{
		execve(command, args, environ);
		perror("./simple_shell");
		exit(EXIT_FAILURE);
	}
	path = getenv("PATH");
	if (!path)
		return;

	path_copy = strdup(path);
	token = strtok(path_copy, ":");
	while (token)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				execve(full_path, args, environ);
				perror("./simple_shell");
				exit(EXIT_FAILURE);
			}
			else if (pid > 0)
				wait(&status);

			free(path_copy);
			return;
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	fprintf(stderr, "%s: comando no encontrado\n", command);
}
