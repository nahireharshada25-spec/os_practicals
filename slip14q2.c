#include <stdio.h>

int main()
{
    int page[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int frame[10], n;
    int i, j, k = 0, found, fault = 0;

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
            if (frame[j] == page[i])
                found = 1;
        }

        if (found == 0)
        {
            frame[k] = page[i];
            k = (k + 1) % n;
            fault++;
        }

        printf("%d\t", page[i]);

        for (j = 0; j < n; j++)
        {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }

        if (found)
            printf("\tNo Fault\n");
        else
            printf("\tPage Fault\n");
    }

    printf("\nTotal Page Faults = %d\n", fault);

    return 0;
}
