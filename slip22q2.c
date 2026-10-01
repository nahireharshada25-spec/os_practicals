#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, time = 0, count = 0;
    int at[10], bt[10], pr[10], ct[10], tat[10], wt[10];
    int done[10] = {0}, p, min, burst;
    float awt = 0, atat = 0;

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
    }

    printf("\nGantt Chart:\n");

    while (count < n)
    {
        p = -1;
        min = 999;

        for (i = 0; i < n; i++)
        {
            if (done[i] == 0 && at[i] <= time && pr[i] < min)
            {
                min = pr[i];
                p = i;
            }
        }

        if (p == -1)
        {
            time++;
            continue;
        }

        burst = rand() % 5 + 1;
        printf("| P%d ", p + 1);

        time = time + burst;
        ct[p] = time;

        tat[p] = ct[p] - at[p];
        wt[p] = tat[p] - bt[p];

        if (wt[p] < 0)
            wt[p] = 0;

        awt = awt + wt[p];
        atat = atat + tat[p];

        done[p] = 1;
        count++;
    }

    printf("|\n");

    printf("\nProcess\tAT\tBT\tPriority\tTAT\tWT\n");

    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               i + 1, at[i], bt[i], pr[i], tat[i], wt[i]);

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f\n", atat / n);

    return 0;
}
