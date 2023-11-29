#include <stdio.h>

int main()
{
    int i, j, k, n, f, max, pf = 0;
    int rs[25], frame[10], next[25];

    printf("\nEnter the length of reference string -- ");
    scanf("%d", &n);

    printf("\nEnter the reference string -- ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &rs[i]);
    }

    printf("\nEnter no. of frames -- ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
    {
        frame[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        int flag = 0;

        // Check if page is already in frame
        for (j = 0; j < f; j++)
        {
            if (frame[j] == rs[i])
            {
                flag = 1;
                break;
            }
        }

        // If not in frame,
        if (flag == 0)
        {

            // To check if empty frame is available-

            int flag1 = 0; // Initialize to -1, indicating no empty frame found
            for (j = 0; j < f; j++)
            {
                if (frame[j] == -1)
                {
                    frame[j] = rs[i];
                    flag1 = 1;
                    pf++;
                    break; // Found an empty frame, exit the loop
                }
            }

            // If empty frame not found, perform optimal replacement i.e find the page with the furthest future reference
            if (flag1 == 0)
            {
                max = -1;
                int index = 0;
                for (j = 0; j < f; j++)
                {
                    int found = 0;
                    for (k = i + 1; k < n; k++)
                    {
                        if (frame[j] == rs[k])
                        {
                            found = 1;
                            break;
                        }
                    }
                    if (found == 0)
                    {
                        next[j] = n;
                    }
                    else
                    {
                        next[j] = k;
                    }
                    if (next[j] > max)
                    {
                        max = next[j];
                        index = j;
                    }
                }
                frame[index] = rs[i];
                pf++;
            }
        }

        // Print current page and frame
        printf("%d\t", rs[i]);
        for (j = 0; j < f; j++)
        {
            printf("%d\t", frame[j]);
        }

        // If there was a page fault, print the page fault number
        if (flag == 0)
        {
            printf("PF No. %d", pf);
        }
        printf("\n");
    }

    printf("\nThe number of page faults using Optimal algorithm are %d", pf);

    return 0;
}