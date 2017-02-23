#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int queue[100], q_front=0, q_end=0;

void sort_bt(int bt[])
{
	for(int i=q_front;i<q_end-1;i++)
		for(int j=q_front;j<q_front+q_end-i-1;j++)
			if(bt[queue[j]]>bt[queue[j+1]])
			{
				int temp = queue[j];
				queue[j] = queue[j+1];
				queue[j+1] = temp;
			}
}

int main()
{
	int n;
	printf("Enter no of processes: ");
	scanf("%d", &n);
	int  at[n], bt[n], bt_comp[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, ct[n], tat[n], wt[n];
	char p[n][3];
	for(int i=0;i<n;i++)
	{
		printf("\nEnter arrival time and burst time:");
		scanf("%d %d", &at[i], &bt[i]);
		strcpy(p[i],"\n");
		p[i][0] = 'P';
		p[i][1] = i+'1';
		p[i][2] = '\0';
	}
	
	for(int i=0;i<n-1;i++)
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
				char tmp[] = "\0";
				strcpy(tmp, p[j]);
				strcpy(p[j], p[j+1]);
				strcpy(p[j+1], tmp);
			}
		}
	}

	int cpu_timer = 0;
	int count_comp = 0;
	fflush(stdout);
	printf("\n\nGantt Chart :-");
	fflush(stdout);
	while(1)
	{
		for(int i=0;i<n;i++)
			if(at[i]==cpu_timer)
				queue[q_end++] = i;
		if(cpu_timer==0)
			sort_bt(bt);
		
		if(q_end!=q_front)
		{
			if(bt_comp[queue[q_front]]==bt[queue[q_front]])
			{
				ct[queue[q_front]] = cpu_timer;
				fflush(stdout);
				printf("%d %s %d\t", cpu_timer - bt[queue[q_front]], p[queue[q_front]], ct[queue[q_front]]);
				fflush(stdout);
				q_front++;
				count_comp++;
				if(count_comp==n)
					goto abc;
				sort_bt(bt);
			}
			bt_comp[queue[q_front]]++;
		}
		if(count_comp==n)
			break;
		cpu_timer++;
	}
	abc: printf("\n");

	float sum_tat = 0, sum_wt = 0;
	for(int i=0; i<n;i++)
	{
		tat[i] = ct[i] - at[i];
		sum_tat += tat[i];
		wt[i] = tat[i] - bt[i];
		sum_wt += wt[i];
	}

	fflush(stdout);
	printf("\n\nProcess  Arrival  Burst  Completion  Turnaround  Waiting\n");
	fflush(stdout);
	for(int i=0;i<n;i++)
	{
		fflush(stdout);
		printf("%s\t %d\t  %d\t %d\t     %d\t\t %d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
		fflush(stdout);
	}

	fflush(stdout);
	printf("\n\nAvg. Turnaround time = %f\nAvg. Waiting time = %f\n", sum_tat/n, sum_wt/n);
	fflush(stdout);
	return 0;
}
