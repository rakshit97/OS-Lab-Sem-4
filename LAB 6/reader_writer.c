#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t read_count_request;
sem_t db;
int read_count;

void *Writer(void *arg)
{
	sleep(1);
	int temp = (int)arg;
	printf("\nWriter %d is trying to enter into database for modifying the data", temp);
	sem_wait(&db);
	printf("\nWriter %d is writing into the database", temp);
	printf("\nWriter %d is leaving the database", temp);
	sem_post(&db);
}

void *Reader(void *arg)
{
	sleep(1);
	int temp = (int)arg;
	printf("\nReader %d is trying to enter into the Database for reading the data", temp);
	sem_wait(&read_count_request);
	read_count++;
	if(read_count==1)
	{
		sem_wait(&db);
		printf("\nReader %d is reading the database", temp);
	}
	sem_post(&read_count_request);
	sem_wait(&read_count_request);
	read_count--;
	if(read_count==0)
	{
		printf("\nReader %d is leaving the database", temp);
		sem_post(&db);
	}
	sem_post(&read_count_request);
}

void initialize()
{
	sem_init(&read_count_request,0,1);
	sem_init(&db,0,1);
	read_count = 0;
}

int main()
{
	int i=0,n1=0,n2=0;
	initialize();
	pthread_t R_thrs[100],W_thrs[100];
	printf("\nEnter number of Readers thread: ");
	scanf("%d", &n1);
	printf("\nEnter number of Writers thread: ");
	scanf("%d", &n2);

	for(i=0;i<n1;i++)
		pthread_create(&R_thrs[i], NULL, Reader, (void*)i);
	for(i=0;i<n2;i++)
		pthread_create(&W_thrs[i], NULL, Writer, (void*)i);
	for(i=0;i<n2;i++)
		pthread_join(W_thrs[i], NULL);
	for(i=0;i<n1;i++)
		pthread_join(R_thrs[i], NULL);

	sem_destroy(&db);
	sem_destroy(&read_count_request);

	return 0;
}
