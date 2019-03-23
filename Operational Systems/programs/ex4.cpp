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
		for(i = 0; i < 10; i++)
		{
			wait(NULL);
			printf("filho %d\n", i);
		}
	}
	else
	{
		for(i = 0; i < 5; i++)
		{
			printf("pai %d\n", j);
		}
	}
	return 0;
}