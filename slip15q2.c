#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, time = 0, done = 0;
    int at[10], bt[10], pr[10], rem[10];
    int ct[10], wt[10], tat[10];
    int p, min, totalwt = 0, totaltat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nP%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d First CPU Burst: ", i + 1);
        scanf("%d", &bt[i]);

        printf("P%d Priority: ", i + 1);
        scanf("%d", &pr[i]);

        /* Next CPU burst */
        bt[i] = bt[i] + (rand() % 5 + 1);

        rem[i] = bt[i];
    }

    printf("\nGantt Chart:\n");

    while (done < n)
    {
        p = -1;
        min = 999;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rem[i] > 0 && pr[i] < min)
            {
                min = pr[i];
                p = i;
            }
        }

        if (p == -1)
        {
            time++;
        }
        else
        {
            printf("| P%d ", p + 1);

            rem[p]--;
            time++;

            if (rem[p] == 0)
            {
                ct[p] = time;
                tat[p] = ct[p] - at[p];
                wt[p] = tat[p] - bt[p];

                totalwt += wt[p];
                totaltat += tat[p];

                done++;
            }
        }
    }

    printf("|\n");

    printf("\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               i + 1, at[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
           (float)totalwt / n);

    printf("\nAverage Turnaround Time = %.2f\n",
           (float)totaltat / n);

    return 0;
}
