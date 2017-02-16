#include<stdio.h>
#include<unistd.h>

int main()
{
	int pid = fork();
	if(pid>0)
		printf("Parent, pid: %d, ppid: %d\n", getpid(), getppid());
	else if(pid==0)
	{
		printf("Child, pid: %d, ppid: %d\n", getpid(), getppid());
	}
	return 0;
}
