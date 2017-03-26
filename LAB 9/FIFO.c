#include<stdio.h>

int main()
{
	int nf, np;
	printf("Enter frame size: ");
	scanf("%d", &nf);
	printf("\nEnter no. of pages:");
	scanf("%d", &np);
	int pages[np];
	printf("\nEnter the pages: \n");

	for (int i=0; i<np; i++)
		scanf("%d", &pages[i]);

	int hash[100] = {0}, frames[nf];
	for(int i=0;i<4;i++)
	{
		hash[pages[i]] = 1;
		frames[i] = pages[i];
	}

	int count=4, pos = 0;
	for (int i=4; i<np; i++)
	{
		if(hash[pages[i]] != 1)
		{
			hash[frames[pos]] = 0;
			hash[pages[i]] = 1;
			frames[pos] = pages[i];
			pos++;
			if(pos>3)
				pos=0;
			count++;
		}
	}

	printf("\n\nNo. of page faults = %d\n\n", count);
	return 0;
}