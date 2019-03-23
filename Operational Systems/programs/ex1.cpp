#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j;
	pid_t id = fork();
	if(id == 0)
	{
		for(i = 0; i < 1000000; i++)
			printf("filho\n");
	}
	else
	{
		for(j = 0; j < 500000; j++)
			printf("pai\n");
	}
	return 0;
}