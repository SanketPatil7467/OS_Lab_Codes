#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define THREAD_NUM 15

pthread_mutex_t mutexBuffer = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t bufferNotFull = PTHREAD_COND_INITIALIZER;
pthread_cond_t bufferNotEmpty = PTHREAD_COND_INITIALIZER;

int buffer[8];
int count = 0;

void printBuffer()
{
    for (int i = 0; i < 8; i++)
    {
        printf("%d\t", buffer[i]);
    }
    printf("\n");
}

void *producer(void *args)
{
    while (1)
    {
        // Produce
        int x = rand() % 100;
        sleep(1);

        // Add to the buffer
        pthread_mutex_lock(&mutexBuffer);

        while (count == 8)
        {
            pthread_cond_wait(&bufferNotFull, &mutexBuffer);
        }

        buffer[count] = x;
        count++;
        printf("Produced %d\n", x);
        printBuffer();
        if (count == 8)
        {
            printf("\n\t\tBuffer is Full\n");
        }

        pthread_cond_signal(&bufferNotEmpty);
        pthread_mutex_unlock(&mutexBuffer);
    }
}

void *consumer(void *args)
{
    while (1)
    {
        int y;

        // Remove from the buffer
        pthread_mutex_lock(&mutexBuffer);

        while (count == 0)
        {
            pthread_cond_wait(&bufferNotEmpty, &mutexBuffer);
        }

        y = buffer[count - 1];
        buffer[count - 1] = 0;

        count--;
        printf("Consumed %d\n", y);
        printBuffer();
        if (count == 0)
        {
            printf("\n\t\tBuffer is Empty\n");
        }

        pthread_cond_signal(&bufferNotFull);
        pthread_mutex_unlock(&mutexBuffer);
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    pthread_t th[THREAD_NUM];
    int i;
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (i < 13)
        {
            if (pthread_create(&th[i], NULL, &producer, NULL) != 0)
            {
                perror("Failed to create thread");
            }
        }
        else
        {
            if (pthread_create(&th[i], NULL, &consumer, NULL) != 0)
            {
                perror("Failed to create thread");
            }
        }
    }
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread");
        }
    }
    return 0;
}