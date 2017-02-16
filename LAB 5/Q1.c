#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	execl("/bin/ls", "", NULL);
	return 0;
}
