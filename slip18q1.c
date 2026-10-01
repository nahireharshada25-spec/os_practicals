#include <stdio.h>

int main()
{
    int n, i, time = 0, done = 0;
    int at[10], bt[10], rem[10];
    int ct[10], wt[10], tat[10];
    int p, min, last = -1;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter AT and BT of P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rem[i] = bt[i];
    }

    printf("\nGantt Chart:\n");

    while (done < n)
    {
        p = -1;
        min = 999;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rem[i] > 0 && rem[i] < min)
            {
                min = rem[i];
                p = i;
            }
        }

        if (p == -1)
        {
            time++;
        }
        else
        {
            if (p != last)
            {
                printf("| P%d ", p + 1);
                last = p;
            }

            rem[p]++;
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

    printf("\nP\tAT\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], wt[i], tat[i]);

        awt += wt[i];
        atat += tat[i];
    }

    printf("\nAverage WT = %.2f", awt / n);
    printf("\nAverage TAT = %.2f\n", atat / n);

    return 0;
}
