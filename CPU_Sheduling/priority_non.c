#include <stdio.h>
#include <stdbool.h>

void NonPrempPriority()
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
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &priority[i]);
    }

    while (true)
    {
        int min = 999, c = -1; // Initialize 'c' to an invalid index
        if (tot == n)
            break;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= st && f[i] == 0 && priority[i] < min)
            {
                min = priority[i];
                c = i; // Store the index of the process with the shortest burst time
            }
        }

        if (c == -1)
            st++;
        else
        {
            ct[c] = st + bt[c];
            st = ct[c]; // Update 'st' to the completion time of the scheduled process
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
    NonPrempPriority();
    return 0;
}