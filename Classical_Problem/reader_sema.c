#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

sem_t sema, wrt;
int readcount = 0;

void *reader() {
    while (1) {
        sem_wait(&sema);
        readcount++;
        printf("Reader entered, Readcount: %d\n", readcount);
        if (readcount == 1) {
            sem_wait(&wrt);
            printf("Writer blocked\n");
        }
        sem_post(&sema);

        // --READ THE FILE?
        printf("Reading the file\n");

        sem_wait(&sema);
        readcount--;
        printf("Reader exited, Readcount: %d\n", readcount);
        if (readcount == 0) {
            sem_post(&wrt);
            printf("Writer unblocked\n");
        }
        sem_post(&sema);
        sleep(2); // Sleep to simulate some work
    }
}

void *writer() {
    while (1) {
        sleep(1); // Sleep to simulate some work
        sem_wait(&wrt);
        printf("Writer entered\n");

        // WRITE INTO THE FILE
        printf("Writing the file\n");

        sem_post(&wrt);
        printf("Writer exited\n");
        sleep(3); // Sleep to simulate some work
    }
}

int main() {
    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];
    sem_init(&sema, 0, 1);
    sem_init(&wrt, 0, 1);

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_create(&readers[i], NULL, reader, NULL);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_create(&writers[i], NULL, writer, NULL);
    }

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

  return 0;
}