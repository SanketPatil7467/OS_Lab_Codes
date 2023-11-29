#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void createFile()
{
    char fileName[50];
    int fd;

    printf("Enter the file name to create: ");
    scanf("%s", fileName);

    fd = open(fileName, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error creating file");
        return;
    }

    printf("File created successfully: %s\n", fileName);
    close(fd);
}

void readFile()
{
    char fileName[50];
    char buffer[100];
    int fd, bytesRead;

    printf("Enter the file name to read: ");
    scanf("%s", fileName);

    fd = open(fileName, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return;
    }

    bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead == -1)
    {
        perror("Error reading file");
        close(fd);
        return;
    }

    printf("Content of %s:\n%s\n", fileName, buffer);
    close(fd);
}

void writeFile()
{
    char fileName[50];
    char data[100];

    printf("Enter the file name to write: ");
    scanf("%s", fileName);

    printf("Enter data to write to %s (max 100 characters):\n", fileName);
    scanf(" %[^\n]", data);

    int fd = open(fileName, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error opening file for writing");
        return;
    }

    if (write(fd, data, sizeof(data)) == -1)
    {
        perror("Error writing to file");
        close(fd);
        return;
    }

    printf("Data written to %s successfully.\n", fileName);
    close(fd);
}

void linkFile()
{
    char existingFile[50], newLink[50];

    printf("Enter the existing file name: ");
    scanf("%s", existingFile);

    printf("Enter the new link name: ");
    scanf("%s", newLink);

    if (link(existingFile, newLink) == -1)
    {
        perror("Error creating link");
        return;
    }

    printf("Link created successfully.\n");
}

void unlinkFile()
{
    char fileName[50];

    printf("Enter the file name to unlink: ");
    scanf("%s", fileName);

    if (unlink(fileName) == -1)
    {
        perror("Error unlinking file");
        return;
    }

    printf("File unlinked successfully.\n");
}

int main()
{
    int choice;

    do
    {
        printf("\nFile System Operations Menu\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Write File\n");
        printf("4. Link File\n");
        printf("5. Unlink File\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createFile();
            break;
        case 2:
            readFile();
            break;
        case 3:
            writeFile();
            break;
        case 4:
            linkFile();
            break;
        case 5:
            unlinkFile();
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
