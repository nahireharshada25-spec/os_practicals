#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, time = 0, done = 0;
    int at[10], bt[10], used[10] = {0};
    int ct[10], wt[10], tat[10];
    int p, min;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and First CPU Burst of P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);

        /* Next CPU burst */
        bt[i] = bt[i] + 1;
    }

    printf("\nGantt Chart:\n");

    while (done < n)
    {
        p = -1;
        min = 999;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && used[i] == 0)
            {
                if (bt[i] < min)
                {
                    min = bt[i];
                    p = i;
                }
            }
        }

        if (p == -1)
        {
            time++;
        }
        else
        {
            printf("| P%d ", p + 1);

            time = time + bt[p];

            ct[p] = time;
            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];

            used[p] = 1;
            done++;
        }
    }

    printf("|\n");

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    float awt = 0, atat = 0;

    for (i = 0; i < n; i++)
    {
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f\n", atat / n);

    return 0;
}
