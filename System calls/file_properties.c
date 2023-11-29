#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main()
{
    char filename[100];
    struct stat fileStat;

    // Prompt the user for the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Use stat to retrieve file properties
    if (stat(filename, &fileStat) < 0)
    {
        perror("Error");
        return 1;
    }

    // Print the properties
    printf("File Properties for '%s':\n", filename);
    printf("1. File Size: %ld bytes\n", fileStat.st_size);
    printf("2. Inode Number: %ld\n", fileStat.st_ino);
    printf("3. Owner User ID: %d\n", fileStat.st_uid);
    printf("4. Owner Group ID: %d\n", fileStat.st_gid);
    printf("5. Permissions (in octal): %o\n", fileStat.st_mode & 0777);
    printf("6. Number of Hard Links: %ld\n", fileStat.st_nlink);
    printf("7. Device ID (if special file): %ld\n", fileStat.st_rdev);
    printf("8. Last Access Time: %s", ctime(&fileStat.st_atime));
    printf("9. Last Modification Time: %s", ctime(&fileStat.st_mtime));
    printf("10. Last Status Change Time: %s", ctime(&fileStat.st_ctime));

    return 0;
}
