#include<stdio.h>
int main()
{
	int i,j,sum=0,n;
	int d[20];
	int head,temp,dloc, tail;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	printf("\nEnter position of head: ");
	scanf("%d",&head);
	printf("\nEnter position of tail: ");
	scanf("%d",&tail);
	printf("\nEnter the queue: \n");
	for(i=0;i<n;i++)
		scanf("%d",&d[i]);
	
	d[n]=head;
	n=n+1;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(d[i]>d[j])
			{
				temp=d[i];
				d[i]=d[j];
				d[j]=temp;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		if(head==d[i])
		{
			dloc=i;
			break;
		}
	}

	if(dloc>tail/2)
	{
		for(i=dloc;i<n;i++)
		{
			printf("%d -> ",d[i]);
			if(i>dloc+1)
				sum+=(d[i] - d[i-1]);
		}
		printf("%d -> ", tail);
		sum+=(tail-d[i-1]);
		sum+=(tail-d[dloc-1]);
		for(i=dloc-1;i>=0;i--)
		{
			printf("%d -> ",d[i]);
			if(i<dloc-1)
				sum+=(d[i+1]-d[i]);
		}
	}
 
	else
	{
		for(i=dloc;i>=0;i--)
		{
			printf("%d -> ",d[i]);
			if(i<dloc)
				sum+=(d[i+1]-d[i]);
		}
			sum+=d[i+1];
			sum+=d[dloc+1];
		printf("0 -> ");
		for(i=dloc+1;i<n;i++)
		{
			printf("%d -> ",d[i]);
			if(i>dloc+1)
				sum+=(d[i]-d[i-1]);
		}
	}
	printf("end");
	printf("\nMovement of total cylinders %d \n",sum);
	return 0;
}
