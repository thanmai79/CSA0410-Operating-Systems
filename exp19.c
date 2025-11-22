#include <stdio.h>
#include <pthread.h>

// Shared variable
int counter = 0;

// Mutex variable
pthread_mutex_t mutex;

// Thread function
void* threadFunction(void* arg) {
    for (int i = 0; i < 1000000; ++i) {
        pthread_mutex_lock(&mutex);   // Enter critical section
        counter++;                    // Shared counter increment
        pthread_mutex_unlock(&mutex); // Exit critical section
    }
    return NULL;
}

int main() {

    pthread_t thread1, thread2;

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_create(&thread1, NULL, threadFunction, NULL);
    pthread_create(&thread2, NULL, threadFunction, NULL);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    // Print final value
    printf("Final counter value: %d\n", counter);

    return 0;
}
