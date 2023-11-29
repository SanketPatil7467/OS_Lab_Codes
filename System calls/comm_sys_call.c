// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <fcntl.h>
// #include <string.h>
// #include <sys/stat.h>

// #define BUFFER_SIZE 256

// void regularPipeExample()
// {
//     int pipefd[2];
//     char buffer[BUFFER_SIZE];
//     pid_t childpid;

//     if (pipe(pipefd) == -1)
//     {
//         perror("Pipe creation failed");
//         return;
//     }

//     childpid = fork();

//     if (childpid == -1)
//     {
//         perror("Fork failed");
//         return;
//     }

//     if (childpid == 0)
//     {
//         // Child process (writes to the pipe)
//         close(pipefd[0]); // Close unused read end

//         char message[] = "Hello from the child process!";
//         write(pipefd[1], message, strlen(message) + 1);
//         close(pipefd[1]); // Close write end

//         exit(EXIT_SUCCESS);
//     }
//     else
//     {
//         // Parent process (reads from the pipe)
//         close(pipefd[1]); // Close unused write end

//         read(pipefd[0], buffer, sizeof(buffer));
//         printf("Parent received: %s\n", buffer);

//         close(pipefd[0]); // Close read end
//         wait(NULL);       // Wait for child process to finish
//     }
// }

// void namedPipeExample()
// {
//     const char *pipeName = "my_named_pipe";
//     char buffer[BUFFER_SIZE];
//     pid_t childpid;

//     if (mkfifo(pipeName, 0666) == -1)
//     {
//         perror("Named pipe creation failed");
//         return;
//     }

//     childpid = fork();

//     if (childpid == -1)
//     {
//         perror("Fork failed");
//         return;
//     }

//     if (childpid == 0)
//     {
//         // Child process (writes to the named pipe)
//         int fd = open(pipeName, O_WRONLY);
//         if (fd == -1)
//         {
//             perror("Child: Open failed");
//             return;
//         }

//         char message[] = "Hello from the child process!";
//         write(fd, message, strlen(message) + 1);
//         close(fd);

//         exit(EXIT_SUCCESS);
//     }
//     else
//     {
//         // Parent process (reads from the named pipe)
//         int fd = open(pipeName, O_RDONLY);
//         if (fd == -1)
//         {
//             perror("Parent: Open failed");
//             return;
//         }

//         read(fd, buffer, sizeof(buffer));
//         printf("Parent received: %s\n", buffer);

//         close(fd);
//         wait(NULL);
//     }

//     // Remove the named pipe after use
//     unlink(pipeName);
// }

// int main()
// {
//     int choice;

//     do
//     {
//         printf("\nCommunication System Calls Menu\n");
//         printf("1. Regular Pipe Example\n");
//         printf("2. Named Pipe Example\n");
//         printf("0. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             regularPipeExample();
//             break;
//         case 2:
//             namedPipeExample();
//             break;
//         case 0:
//             printf("Exiting the program.\n");
//             break;
//         default:
//             printf("Invalid choice. Please enter a valid option.\n");
//         }
//     } while (choice != 0);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define NAMED_PIPE "/tmp/named_pipe"

void parentProcess(int unnamedPipe)
{
    char message[] = "Hello from parent";

    // Write to the named pipe
    int namedPipe = open(NAMED_PIPE, O_WRONLY);
    write(namedPipe, message, sizeof(message));

    // Write to the unnamed pipe
    write(unnamedPipe, message, sizeof(message));

    close(namedPipe);
    close(unnamedPipe);
}

void childProcess(int unnamedPipe)
{
    char buffer[100];

    // Read from the named pipe
    int namedPipe = open(NAMED_PIPE, O_RDONLY);
    read(namedPipe, buffer, sizeof(buffer));
    printf("Child received from named pipe: %s\n", buffer);

    // Read from the unnamed pipe
    read(unnamedPipe, buffer, sizeof(buffer));
    printf("Child received from unnamed pipe: %s\n", buffer);

    close(namedPipe);
    close(unnamedPipe);
}

int main()
{
    mkfifo(NAMED_PIPE, 0666);

    int unnamedPipe[2];
    pipe(unnamedPipe);

    pid_t pid = fork();

    if (pid == 0)
    {
        childProcess(unnamedPipe[0]);
    }
    else
    {
        parentProcess(unnamedPipe[1]);
    }

    unlink(NAMED_PIPE);

    return 0;
}
