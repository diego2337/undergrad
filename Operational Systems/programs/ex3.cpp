#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void forkMultiple(int n)
{	
	int i;
	for(i = 1; i <= n; i++)
	{
		pid_t id = fork();
		if(id == 0)
		{
			printf("filho %d\n", i);
		}
		else
			printf("JA FAZ TEMPO\n");
	}

}
	
int main(void)
{
	int n;
	scanf("%d", &n);
	forkMultiple(n);
	wait(NULL);
	printf("pai\n");
	return 0;
}