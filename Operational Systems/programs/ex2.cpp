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
		while(1)
		{
			printf("filho\n");
			sleep(1);
		}
	}
	else
	{
		while(1)
		{
			printf("pai\n");
			sleep(1);
		}
	}
	return 0;
}