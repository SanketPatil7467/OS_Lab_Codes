#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

void processSystemCalls()
{
    int choice;
    pid_t childPid;
    int status;

    do
    {
        printf("\nProcess System Calls Menu:\n");
        printf("1. Fork\n");
        printf("2. Exit\n");
        printf("3. Wait\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            childPid = fork();
            if (childPid == 0)
            {
                printf("Child process: PID=%d, Parent PID=%d\n", getpid(), getppid());
            }
            else if (childPid > 0)
            {
                printf("Parent process: Child PID=%d\n", childPid);
                wait(&status);
            }
            else
            {
                perror("Fork failed");
            }
            break;

        case 2:
            exit(0);
            break;

        case 3:
            wait(&status);
            printf("Child process finished with status: %d\n", status);
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);
}

void main()
{
    processSystemCalls();
}