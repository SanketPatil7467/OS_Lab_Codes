#include <stdio.h>

void main()
{
    int i, j, f, pf = 0, rs[25], frame[10], n, age[10];
    printf("\n Enter the length of reference string -- ");
    scanf("%d", &n);
    printf("\n Enter the reference string -- ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &rs[i]);
    }
    printf("\n Enter no. of frames -- ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
    {
        frame[i] = -1;
        age[i] = 0;
    }

    printf("\n The Page Replacement Process is -- \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", rs[i]);
        int found = 0;
        for (j = 0; j < f; j++)
        {
            if (frame[j] == rs[i])
            {
                age[j] = 0;
                found = 1; // no page fault
                break;
            }
        }
        // Inside the loop where you check for page fault
        if (!found) // page fault
        {
            int flag = 0; // Initialize to -1, indicating no empty frame found
            for (j = 0; j < f; j++)
            {
                if (frame[j] == -1)
                {
                    // printf("\nEmpty frame");
                    frame[j] = rs[i];
                    age[j] = 0;
                    flag = 1;
                    break; // Found an empty frame, exit the loop
                }
            }

            if (flag == 0)
            {
                // If no empty frame is available, perform LRU replacement as before
                int max_age = age[0];
                int max_age_index = 0;
                for (j = 1; j < f; j++)
                {
                    if (age[j] > max_age)
                    {
                        max_age = age[j];
                        max_age_index = j;
                    }
                }
                frame[max_age_index] = rs[i];
                age[max_age_index] = 0;
            }

            pf++; // Increment page fault count
        }

        // If there was a page fault, print the page fault number

        for (j = 0; j < f; j++)
        {
            printf("\t%d", frame[j]);
            age[j]++;
        }

        if (!found)
        {
            printf("\t\t\tPF No. %d", pf);
        }

        printf("\n");
    }
    printf("\n The number of Page Faults using LRU are %d", pf);
}
