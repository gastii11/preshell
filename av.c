#include <stdio.h>

/**
 * main - Prints all arguments passed to the program, one per line
 * @ac: Argument count (unused)
 * @av: Argument vector (array of strings)
 * Return: Always 0 (Success)
 */

int main(int ac, char **av)
{
	int i = 1;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
