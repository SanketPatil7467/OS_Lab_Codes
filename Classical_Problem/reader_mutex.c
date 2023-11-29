#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t wrt = PTHREAD_MUTEX_INITIALIZER;
int readcount = 0;

void *reader() {
    while (1) {
        pthread_mutex_lock(&mutex);
        readcount++;
        printf("Reader entered, Readcount: %d\n", readcount);
        if (readcount == 1) {
            pthread_mutex_lock(&wrt);
            printf("Writer blocked\n");
        }
        pthread_mutex_unlock(&mutex);

        // --READ THE FILE?
        printf("Reading the file\n");

        pthread_mutex_lock(&mutex);
        readcount--;
        printf("Reader exited, Readcount: %d\n", readcount);
        if (readcount == 0) {
            pthread_mutex_unlock(&wrt);
            printf("Writer unblocked\n");
        }
        pthread_mutex_unlock(&mutex);
        sleep(2); // Sleep to simulate some work
    }
}

void *writer() {
    while (1) {
        sleep(1); // Sleep to simulate some work

        pthread_mutex_lock(&wrt);
        printf("Writer entered\n");

        // WRITE INTO THE FILE
        printf("Writing the file\n");

        pthread_mutex_unlock(&wrt);
        printf("Writer exited\n");

        sleep(3); // Sleep to simulate some work
    }
}

int main() {
    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];

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