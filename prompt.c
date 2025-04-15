#include <stdio.h>
#include <stdlib.h>

/**

 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("$ ");

		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("getline");
				return (-1);
			}
		}
		printf("Leiste: %s", line);
	}
	free(line);

	return (0);
}
