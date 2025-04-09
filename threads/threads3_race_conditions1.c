#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

struct thread_struct
{
	pthread_t id;
	int *shared_counter;
};

void *print_message(void *th)
{
	struct thread_struct *thread = (struct thread_struct *)th;
	(*thread->shared_counter)++;
	printf("Thread %ld is running!\n", thread->id);
	printf("\n count %d!\n", *thread->shared_counter);
	pthread_exit(0);
}

int main()
{
	int count = 0;
	struct thread_struct thread[8];

	for (int i = 0; i < 8; i++)
	{
		thread[i].shared_counter = &count;
		pthread_create(&thread[i].id, NULL,print_message, &thread[i]);
	}
	for (int i = 0;i < 8; i++)
        pthread_join(thread[i].id, NULL);
	printf("Final count: %d\n", count);
	return (0);
}
