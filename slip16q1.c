#include <stdio.h>

int main()
{
    int a[] = {3, 5, 7, 2, 5, 1, 2, 3, 1, 3, 5, 3, 1, 6, 2};
    int f[10], c[10];
    int n, i, j, time = 0, fault = 0;
    int found, pos, min;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        f[i] = -1;

    printf("\nPage\tFrames\tStatus\n");

    for (i = 0; i < 15; i++)
    {
        time++;
        found = 0;

        for (j = 0; j < n; j++)
        {
            if (f[j] == a[i])
            {
                found = 1;
                c[j] = time;
                break;
            }
        }

        if (found == 0)
        {
            fault++;
            pos = -1;

            for (j = 0; j < n; j++)
            {
                if (f[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
            {
                min = c[0];
                pos = 0;

                for (j = 1; j < n; j++)
                {
                    if (c[j] < min)
                    {
                        min = c[j];
                        pos = j;
                    }
                }
            }

            f[pos] = a[i];
            c[pos] = time;
        }

        printf("%d\t", a[i]);

        for (j = 0; j < n; j++)
        {
            if (f[j] == -1)
                printf("- ");
            else
                printf("%d ", f[j]);
        }

        if (found)
            printf("\tNo Fault\n");
        else
            printf("\tPage Fault\n");
    }

    printf("\nTotal Page Faults = %d\n", fault);

    return 0;
}
