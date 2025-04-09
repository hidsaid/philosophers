#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


struct thread_struct
{
	pthread_mutex_t	fr;
	pthread_t id;
	int *shared_counter;
};

struct thread_st
{
	pthread_mutex_t	fr;
	struct thread_struct thread[8];
};
void *print_message(void *th)
{
	struct thread_st *thr = (struct thread_st *)th;
	pthread_mutex_lock(&thr->fr);
	(*thr->thread->shared_counter)++;
	printf("Thread %ld is running!\n", thr->thread->id);
	printf("\n count %d!\n", *thr->thread->shared_counter);
	pthread_mutex_unlock(&thr->fr);
	pthread_exit(0);
}

int main()
{
	int count = 0;
	struct thread_st th;
	pthread_mutex_init(&th.fr, NULL);

	for (int i = 0; i < 8; i++)
	{
		th.thread[i].shared_counter = &count;
		pthread_create(&th.thread[i].id, NULL,print_message, &th);
	}
	for (int i = 0;i < 8; i++)
        pthread_join(th.thread[i].id, NULL);
	printf("Final count: %d\n", count);
	return (0);
}
