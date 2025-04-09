#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *sum_args(void *arg)
{
    long i = 0;
    long long *limit;
    long long sum = 0;
    long long *answer;

    limit = malloc(sizeof(long long));
    *limit = *(long long *)arg;
    while (i <= *limit)
    {
        sum += i;
        i++;
    }
    //printf("%lld\n", sum);
    free(limit);
    answer = malloc(sizeof(long long));
    *answer = sum;
    pthread_exit(answer);
}

int main(int argc, char *argv[])
{
    long long limit;
    long long *result;
    pthread_t tid;
    pthread_attr_t attr;

    if (argc < 2)
    {
		printf("Usage: %s <num1> <num2> ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    pthread_attr_init(&attr);
    limit = atoll(argv[1]);
    pthread_create(&tid, &attr, sum_args, &limit);
    result = malloc(sizeof(long long));
    pthread_join(tid, (void **)&result);
    printf("%lld\n", *result);
    return (0);
}
