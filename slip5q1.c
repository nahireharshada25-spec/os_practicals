#include <stdio.h>

int main()
{
    int frame[10], ref[15] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int n, i, j, k = 0, fault = 0, found;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");

    for (i = 0; i < 15; i++)
    {
        found = 0;

        for (j = 0; j < n; j++)
        {
            if (frame[j] == ref[i])
                found = 1;
        }

        if (found == 0)
        {
            frame[k] = ref[i];
            k = (k + 1) % n;
            fault++;
        }

        printf("%d\t", ref[i]);

        for (j = 0; j < n; j++)
            printf("%d ", frame[j]);

        if (found == 0)
            printf("\tFault");
        else
            printf("\tNo Fault");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", fault);

    return 0;
}
