#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

//long long sum;

struct sum_struct
{
	long long limit;
	long long answer;
};

void *sum_args(void *arg)
{
	long i = 0;
	struct sum_struct *arg1 = (struct sum_struct *)arg;
	long long sum;

	sum = 0;
	while (i <= arg1->limit)
	{
		sum += i;
		i++;
	}
	arg1->answer = sum;
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	int args_num, args_num1;
	pthread_attr_t attr;

	if (argc < 2)
	{
		printf("Usage: %s <num>\n", argv[0]);
		exit(-1);
	}
	args_num = argc - 1;
	pthread_t tid[args_num];
	struct sum_struct args[args_num];

	for (int i = 0; i < args_num; i++)
	{
		args[i].limit = atoll(argv[i + 1]);
		pthread_attr_init(&attr);
		pthread_create(&tid[i], &attr,sum_args, &args[i]);
		//printf("%ld\n",(long int)tid[i]);
	}
	for (int i = 0; i < args_num; i++)
	{
		pthread_join(tid[i], NULL);
		printf("sum %lld\n", args[i].answer);
	}
	return (0);
}
