#include <stdio.h>
#include <unistd.h>

int main ()
{
	printf("el PID es: %d\n", getppid());
	return (0);
}
