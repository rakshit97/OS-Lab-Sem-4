#include<stdio.h>

int np, nh;

void get_holes_config(int hole[], int hole_filled[])
{
	printf("\nEnter hole size for each hole: \n");
	for(int j=0;j<nh;j++)
	{
		scanf("%d", &hole[j]);
		hole_filled[j] = 0;
	}
}

void get_processes_and_details(int proc_mem_req[], int proc_allctd[])
{
	printf("\nEnter memory requirement for each process: \n");
	for(int j=0;j<np;j++)
	{
		scanf("%d", &proc_mem_req[j]);
		proc_allctd[j]=0;
	}
}

void allot(int hole[], int hole_filled[], int proc_mem_req[], int proc_allctd[])
{
	for(int i=0;i<np;i++)
	{
		printf("\n%d", i);
		for(int j=0;j<nh;j++)
		{
			if(proc_mem_req[i]<=hole[j] && hole_filled[j]==0)
			{
				hole[j]-=proc_mem_req[i];
				hole_filled[j]=i+1;
				proc_allctd[i]=j+1;
				break;
			}
		}
	}
}

void display_info(int hole[], int hole_filled[], int proc_mem_req[], int proc_allctd[])
{
	printf("\n\nHole details: \n");
	for(int j=0;j<nh;j++)
	{
		printf("Hole%d\t\t", j+1);
		if(hole_filled[j]-1<0)
			printf("Allocated - 0\tFree - %d\n", hole[j]);
		else
			printf("Allocated - %d\tFree - %d\n", proc_mem_req[hole_filled[j]-1], hole[j]);
	}
	for(int i=0;i<np;i++)
		if(proc_allctd[i]==0)
			printf("\nProcess%d is not allocated!!!\n", i+1);
}

int main()
{
	printf("Enter no. of holes: ");
	scanf("%d", &nh);
	int hole[nh], hole_filled[nh];
	get_holes_config(hole, hole_filled);
	printf("\nEnter no. of processes: ");
	scanf("%d", &np);
	int proc_mem_req[np], proc_allctd[np];
	get_processes_and_details(proc_mem_req, proc_allctd);
	allot(hole, hole_filled, proc_mem_req, proc_allctd);
	display_info(hole, hole_filled, proc_mem_req, proc_allctd);

	return 0;
}
