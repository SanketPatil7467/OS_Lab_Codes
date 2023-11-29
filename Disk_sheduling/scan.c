#include <stdio.h>
#include <stdlib.h>

int max = 199, min = 0;

void Sort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Scan(int arr[], int head, int n)
{
    int index;
    Sort(arr, n);

    // Calculate head position
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == head)
        {
            index = i;
            break;
        }
    }

    // Scan:-
    for (int i = index; i < n - 1; i++)
    {
        printf("\nHead moved from %d to %d", arr[i], arr[i + 1]);
    }
    printf("\nHead moved from %d to %d", arr[n - 1], max);
    printf("\nHead moved from %d to %d", max, arr[index - 1]);
    for (int i = index - 1; i > 0; i--)
    {
        printf("\nHead moved from %d to %d", arr[i], arr[i - 1]);
    }

    int seek = abs(max - head) + abs(max - arr[0]);
    printf("\nScan Seek time= %d", seek);
}


int main()
{
    int arr[25];
    int n = 0;
    printf("Enter no. of requests: ");
    scanf("%d", &n);

    printf("\nEnter requests: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int head = 0;
    printf("\nEnter head: ");
    scanf("%d", &head);
    arr[n] = head;
    Scan(arr, head, n + 1);

    return 0;
}