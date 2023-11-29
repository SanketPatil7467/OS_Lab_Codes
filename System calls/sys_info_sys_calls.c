#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

void getProcessId()
{
    printf("Process ID: %d\n", getpid());
}

void getUserId()
{
    printf("User ID: %d\n", getuid());
}

void getHostName()
{
    char hostName[256];
    if (gethostname(hostName, sizeof(hostName)) == -1)
    {
        perror("Error getting hostname");
        return;
    }
    printf("Hostname: %s\n", hostName);
}

void getSysInfo()
{
    struct sysinfo sysInfo;
    if (sysinfo(&sysInfo) == -1)
    {
        perror("Error getting system information");
        return;
    }

    printf("Uptime: %ld seconds\n", sysInfo.uptime);
    printf("Total RAM: %lu KB\n", sysInfo.totalram / 1024);
    printf("Free RAM: %lu KB\n", sysInfo.freeram / 1024);
    printf("Number of processes: %d\n", sysInfo.procs);
}

void getParentProcessId()
{
    printf("Parent Process ID: %d\n", getppid());
}

int main()
{
    int choice;

    do
    {
        printf("\nSystem Information Menu\n");
        printf("1. Get Process ID\n");
        printf("2. Get User ID\n");
        printf("3. Get Hostname\n");
        printf("4. Get System Information\n");
        printf("5. Get Parent Process ID\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            getProcessId();
            break;
        case 2:
            getUserId();
            break;
        case 3:
            getHostName();
            break;
        case 4:
            getSysInfo();
            break;
        case 5:
            getParentProcessId();
            break;
        case 0:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
