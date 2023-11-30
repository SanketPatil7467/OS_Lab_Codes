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
