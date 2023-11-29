#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rs[25], frame[10], count, n, f, pf;
    printf("\nEnter the length of reference string- ");
    scanf("%d", &n);
    printf("\nEnter the reference string- ");
    for (int i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("\nEnter number of frames- ");
    scanf("%d", &f);

    for (int i = 0; i < f; i++)
        frame[i] = -1;

    count = 0;
    pf = 0;

    for (int i = 0; i < n; i++)
    {
        int found = 0;

        for (int j = 0; j < f; j++)
        {
            if (frame[j] == rs[i])
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            int flag = 0;
            for (int j = 0; j < f; j++)
            {
                if (frame[j] == -1)
                {
                    flag = 1;
                    frame[j] = rs[i];
                    break;
                }
            }

            if (flag == 0)
            {
                frame[count] = rs[i];
                count++;

                if (count == f)
                    count = 0;
            }

            pf++;
        }

        printf("\n%d ||", rs[i]);
        for (int j = 0; j < f; j++)
        {
            printf("\t%d", frame[j]);
        }
        if (found == 0)
            printf("\tpf. count- %d", pf);
    }
    printf("\nTotal page faults in fifo= %d\n", pf);
    return 0;
}