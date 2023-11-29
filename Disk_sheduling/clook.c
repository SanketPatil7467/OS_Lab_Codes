#include <stdio.h>
#include <stdlib.h>

void Sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}


void CLOOK(int *arr, int head, int n)
{
    Sort(arr, n);
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == head)
        {
            index = i;
            break;
        }
    }
    for (int i = index; i < n - 1; i++)
    {
        printf("\nHead moved from %d to %d", arr[i], arr[i + 1]);
    }

    printf("\nHead moved from %d to %d", arr[n - 1], arr[0]);

    for (int i = 0; i < index - 1; i++)
    {
        printf("\nHead moved from %d to %d", arr[i], arr[i + 1]);
    }
    int c = arr[n - 1] - head + arr[n - 1] - arr[0] + arr[index - 1] - arr[0];
    printf("\nSeek Time: %d", c);
}

int main()
{
    int n = 0;
    printf("Enter no. of requests: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n + 1);
    printf("\nEnter requests: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int head = 0;
    printf("\nEnter head: ");
    scanf("%d", &head);
    arr[n] = head;
    CLOOK(arr, head, n + 1);
}