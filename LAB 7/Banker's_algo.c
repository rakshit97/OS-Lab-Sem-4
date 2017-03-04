#include<stdio.h>

int n1, n2;

int safe_check(int avlbl[], int alctd[n1][n2], int need[n1][n2])
{
	int work[n2];
	for(int i=0;i<n2;i++)
		work[i]=avlbl[i];
	int finish[n1];
	for(int i=0;i<n1;i++)
		finish[i] = 0;
	int p_comp = 1;
	int count = n1*n1;
	int i=0;
	int cond=0;
	while(count>0)
	{
		if(finish[i]==0)
		{
			for(int j=0;j<n2;j++)
				if(need[i][j]>work[j])
				{
					cond=1;
					break;
				}
			if(cond==0)
			{
				for(int j=0;j<n2;j++)
					work[j]+=alctd[i][j];
				finish[i]=p_comp++;
			}
		}
		count--;
		i++;
		if(i==n1)
			i=0;
		cond=0;
	}
	for(int i=0;i<n1;i++)
	{
		if(finish[i]==0)
		{
			cond=1;
			break;
		}
		printf("\n%d", finish[i]);
	}
	return cond;
}

int main()
{
	printf("Enter no of processes and resources: ");
	scanf("%d %d", &n1, &n2);
	int max[n1][n2], alctd[n1][n2], avlbl[n2], need[n1][n2];
	char p[n1][3], r[n2][2];
	for(int i=0;i<n1;i++)
	{
		printf("\nEnter max requirement for each resource:");
		for(int j=0;j<n2;j++)
			scanf("%d", &max[i][j]);

		printf("\nEnter resource allocated for each resource:");
		for(int j=0;j<n2;j++)
		{
			scanf("%d", &alctd[i][j]);
			need[i][j] = max[i][j]-alctd[i][j];
		}
		p[i][0] = 'P';
		p[i][1] = i+'1';
		p[i][2] = '\0';
	}
	for(int i=0;i<n2;i++)
	{
		printf("\nEnter resource available for each resource: ");
		scanf("%d", &avlbl[i]);
		r[i][0] = i+'A';
		r[i][1] = '\0';
	}

	int i = safe_check(avlbl, alctd, need);
	if(i==0)
		printf("\nSafe\n");
	else
		printf("\nUnsafe\n");

	return 0;
}
