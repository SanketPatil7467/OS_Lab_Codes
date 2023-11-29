#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Sort(int *at, int *bt, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
}

void Fcfs()
{
    printf("Enter the number of processes: ");
    int n;
    scanf("%d", &n);

    int pid[n];
    int at[n];
    int bt[n];
    int ct[n];
    int ta[n];
    int wt[n];
    int f[n];
    int k[n];
    int priority[n];
    int i, st = 0, tot = 0;

    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        k[i] = bt[i];
        f[i] = 0;
    }

    Sort(at, bt, n);

    while (true)
    {
        int c = -1; // Initialize 'c' to an invalid index
        if (tot == n)
            break;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= st && f[i] == 0)
            {

                c = i; // Store the index of the process with the shortest burst time
                break;
            }
        }

        if (c == -1)
            st++;
        else
        {
            st = st + bt[c];
            ct[c] = st;
            f[c] = 1;
            tot++;
        }
    }

    for (i = 0; i < n; i++)
    {
        ta[i] = ct[i] - at[i];
        wt[i] = ta[i] - bt[i];
    }

    printf("\nPid|Arrival| Burst |Complete | Turn|Waiting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], ta[i], wt[i]);
    }
}

int main()
{

    Fcfs();
    return 0;
}
