#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* func(void* arg)
{
    printf("Inside the thread\n");
    return NULL;     // thread returns normally
}

void fun()
{
    pthread_t ptid;

    pthread_create(&ptid, NULL, func, NULL);

    printf("This line may be printed before thread terminates\n");

    // Check if created thread is the same as current thread
    if (pthread_equal(ptid, pthread_self()))
        printf("Threads are equal\n");
    else
        printf("Threads are not equal\n");

    // Wait for the created thread
    pthread_join(ptid, NULL);

    printf("This line will be printed after thread ends\n");
}

int main()
{
    fun();
    return 0;
}
