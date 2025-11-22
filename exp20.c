#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, writeBlock;

int data = 0;
int readersCount = 0;

void *reader(void *arg) {
    int i = 0;

    while (i < 10) {

        sem_wait(&mutex);
        readersCount++;

        if (readersCount == 1) {
            sem_wait(&writeBlock);     // First reader blocks writer
        }

        sem_post(&mutex);

        // Reading section
        printf("Reader reads data: %d\n", data);

        sem_wait(&mutex);
        readersCount--;

        if (readersCount == 0) {
            sem_post(&writeBlock);    // Last reader releases writer
        }

        sem_post(&mutex);

        i++;
        usleep(100000);
    }

    return NULL;
}

void *writer(void *arg) {
    int i = 0;

    while (i < 10) {

        sem_wait(&writeBlock);

        // Writing section
        data++;
        printf("Writer writes data: %d\n", data);

        sem_post(&writeBlock);

        i++;
        usleep(150000);
    }

    return NULL;
}

int main() {

    pthread_t readerThread, writerThread;

    sem_init(&mutex, 0, 1);
    sem_init(&writeBlock, 0, 1);

    pthread_create(&readerThread, NULL, reader, NULL);
    pthread_create(&writerThread, NULL, writer, NULL);

    pthread_join(readerThread, NULL);
    pthread_join(writerThread, NULL);

    sem_destroy(&mutex);
    sem_destroy(&writeBlock);

    return 0;
}
