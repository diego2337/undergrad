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
		execlp("/bin/ls", "ls", NULL);
	}
	else
	{
		wait(NULL);
		printf("Pai\n");
	}
	return 0;
}