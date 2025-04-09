#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *increment(void *arg) {
    for (int i = 0; i < 1000; i++) {
        counter++;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create two threads to increment the counter
    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, increment, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print the final value of the counter
    printf("Final counter value: %d\n", counter);
    return 0;
}

