#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, time = 0, done = 0;
    int at[10], bt[10], pr[10], rem[10];
    int ct[10], wt[10], tat[10];
    int p, high, last = -1;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter AT, BT and Priority of P%d: ", i + 1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);

        bt[i] = bt[i] + 1; /* Next CPU burst */
        rem[i] = bt[i];
    }

    printf("\nGantt Chart:\n");

    while (done < n)
    {
        p = -1;
        high = 999;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rem[i] > 0 && pr[i] < high)
            {
                high = pr[i];
                p = i;
            }
        }

        if (p == -1)
            time++;
        else
        {
            if (p != last)
            {
                printf("| P%d ", p + 1);
                last = p;
            }

            rem[p]--;
            time++;

            if (rem[p] == 0)
            {
                ct[p] = time;
                tat[p] = ct[p] - at[p];
                wt[p] = tat[p] - bt[p];
                done++;
            }
        }
    }

    printf("|\n");

    printf("\nP\tAT\tBT\tPriority\tWT\tTAT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               i + 1, at[i], bt[i], pr[i], wt[i], tat[i]);

        awt += wt[i];
        atat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f\n", atat / n);

    return 0;
}
