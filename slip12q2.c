#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, time = 0;
    int at[10], bt[10], wt[10], tat[10], ct[10];
    int total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter First CPU Burst of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        /* Next CPU burst generated randomly */
        srand(i + 1);
        bt[i] = bt[i] + rand() % 5 + 1;
    }

    printf("\nGantt Chart:\n");

    for (i = 0; i < n; i++)
    {
        if (time < at[i])
            time = at[i];

        printf("| P%d ", i + 1);

        time = time + bt[i];
        ct[i] = time;

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }

    printf("|\n");

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
           (float)total_wt / n);

    printf("\nAverage Turnaround Time = %.2f\n",
           (float)total_tat / n);

    return 0;
}
