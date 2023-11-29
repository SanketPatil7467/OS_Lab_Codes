#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("\n Enter the length of reference string- ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the reference string- ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int head;
    printf("\nEnter initial head position- ");
    scanf("%d", &head);

    int seek = 0;
    printf("\nHead moved from %d to %d", head, arr[0]);
    seek += abs(head - arr[0]);
    for (int i = 0; i < n - 1; i++)
    {
        printf("\nHead moved from %d to %d", arr[i], arr[i + 1]);
        seek += abs(arr[i] - arr[i + 1]);
    }
    printf("\nTotal seek time= %d", seek);

    return 0;
}