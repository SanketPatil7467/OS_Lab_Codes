#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
#include <pthread.h>

#define THREAD_NUM 15

int count = 0;
int buffer[8];

sem_t bufferFull;
sem_t bufferEmpty;
sem_t binarySema;

void printBuffer()
{
    for (int i = 0; i < 8; i++)
    {
        printf("%d\t", buffer[i]);
    }
    printf("\n");
}

void *producer()
{
    while (1)
    {
        int x = rand() % 100;
        sleep(1);

        sem_wait(&bufferEmpty);
        sem_wait(&binarySema);

        buffer[count] = x;
        count++;
        printf("Produced : %d\n", x);
        printBuffer();

        if (count == 8)
        {
            printf("\n\t\tBuffer is Full\n");
        }

        sem_post(&binarySema);
        sem_post(&bufferFull);
    }
}

void *consumer()
{
    while (1)
    {
        int y;
        sem_wait(&bufferFull);
        sem_wait(&binarySema);
        y = buffer[count - 1];
        buffer[count - 1] = 0;
        count--;
        printf("Consumed : %d\n", y);
        printBuffer();

        if (count == 0)
        {
            printf("\n\t\tBuffer Empty\n");
        }

        sem_post(&binarySema);
        sem_post(&bufferEmpty);
    }
}

void main()
{
    srand(time(NULL));
    pthread_t th[THREAD_NUM];
    sem_init(&bufferFull, 0, 0);
    sem_init(&bufferEmpty, 0, 8);
    sem_init(&binarySema, 0, 1);

    for (int i = 0; i < THREAD_NUM; i++)
    {
        if (i < 13)
        {
            if (pthread_create(&th[i], NULL, &producer, NULL) != 0)
            {
                perror("Error in creating thread");
            }
        }
        else
        {
            if (pthread_create(&th[i], NULL, &consumer, NULL) != 0)
            {
                perror("Error in creating thread");
            }
        }
    }

    for (int i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Not able to join the threads");
        }
    }
    sem_destroy(&bufferFull);
    sem_destroy(&bufferEmpty);
    sem_destroy(&binarySema);
}