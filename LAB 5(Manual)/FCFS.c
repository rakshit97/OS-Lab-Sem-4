#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	printf("Enter no of processes: ");
	scanf("%d", &n);
	int at[n], bt[n], ct[n], tat[n], wt[n];
	char p[n][3];
	for(int i=0;i<n;i++)
	{
		printf("\nEnter process no, arrival time and burst time:");
		scanf("%s %d %d", p[i], &at[i], &bt[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(at[j]>at[j+1])
			{
				int temp = at[j];
				at[j] = at[j+1];
				at[j+1] = temp;
				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;
				char tmp[3];
				strcpy(tmp, p[j]);
				strcpy(p[j], p[j+1]);
				strcpy(p[j+1], tmp);
			}
		}
	}

	int cpu_timer = 0;
	printf("\n\nGantt Chart :-" );
	for(int i=0;i<n;i++)
	{
		if(at[i]>cpu_timer)
			cpu_timer = at[i];
		ct[i] = cpu_timer + bt[i];
		printf("%d %s %d\t", cpu_timer, p[i], ct[i]);
		cpu_timer+=bt[i];
	}

	float sum_tat = 0, sum_wt = 0;
	for(int i=0; i<n;i++)
	{
		tat[i] = ct[i] - at[i];
		sum_tat += tat[i];
		wt[i] = tat[i] - bt[i];
		sum_wt += wt[i];
	}

	printf("\n\nProcess  Arrival  Burst  Turnaround  Waiting\n");
	for(int i=0;i<n;i++)
		printf("%s\t %d\t  %d\t %d\t     %d\n", p[i], at[i], bt[i], tat[i], wt[i]);

	printf("\n\nAvg. Turnaround time = %f\nAvg. Waiting time = %f", sum_tat/n, sum_wt/n);
	return 0;
}
