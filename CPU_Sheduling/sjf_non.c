#include <stdio.h>

int main() {
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
    int st = 0, tot = 0;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        f[i] = 0;
    }

    while (1) {
        int c = n, min = 999;
        if (tot == n)
            break;

        for (int i = 0; i < n; i++) {
            if (at[i] <= st && f[i] == 0 && bt[i] < min) {
                min = bt[i];
                c = i;
            }
        }

        if (c == n){
            st++;
        }
        else {
            ct[c] = st + bt[c];
            st += bt[c];
            ta[c] = ct[c] - at[c];
            wt[c] = ta[c] - bt[c];
            f[c] = 1;
            tot++;
        }
    }

    printf("\nPid|Arrival| Burst |Complete | Turn|Waiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], ta[i], wt[i]);
    }

    return 0;
}
