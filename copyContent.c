#include <stdio.h>
int main()
{
    FILE *sourceFile, *destinationFile;
    char character;
    char line[1000];

    sourceFile = fopen("example.txt", "r");
    destinationFile = fopen("zz.txt", "w");

    if (sourceFile == NULL || destinationFile == NULL)
    {
        printf("Source file is empty! Can't copy!\n");
        return 1;
    }

    while ((character = fgetc(sourceFile)) != EOF) {
        fputc(character, destinationFile);
    }
    printf("File copied character by character.\n");

    // while (fgets(line, sizeof(line), sourceFile) != NULL)
    // {
    //     fputs(line, destinationFile);
    // }
    // printf("File copied line by line.\n");


    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
