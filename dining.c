#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>

sem_t ch[5],room;
void *philosopher(void *arg)
{
	int i=(int)arg,left,right;
	printf("\n%d Philosopher is created and in thinking mode\n",i);
	sleep(7);
	left=i;
	right=(i+1)%5;
	printf("\n%dPhilosopher is Hungry \n",i);
	sem_wait(&room);
	sem_wait(&ch[left]);
	sleep(20);
	sem_wait(&ch[right]);
	printf("\n%d Philosopher is Eating\n",i);
	sleep(2);
	sem_post(&ch[left]);
	sem_post(&ch[right]);
	printf("\n%dPhilosopher is Terminated\n",i);
	sem_post(&room);
}

		main()
{
	int i;
	pthread_t tid[5];

	for(i=0;i<5;i++)
	{
		sem_init(&ch[i],0,1);
		sem_init(&room,0,4);
		pthread_create(&tid[i],NULL,philosopher,(void *)i);
		sleep(1);
	}
	for(i=0;i<5;i++)
	{
		pthread_join(tid[i],NULL);
	}
}
