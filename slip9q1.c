#include <stdio.h>

int main()
{
    int page[] = {8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2};
    int frame[10], n;
    int i, j, k, found, fault = 0;
    int pos, far, next;

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
            fault++;

            for (j = 0; j < n; j++)
            {
                if (frame[j] == -1)
                {
                    frame[j] = page[i];
                    break;
                }
            }

            if (j == n)
            {
                far = -1;

                for (j = 0; j < n; j++)
                {
                    next = 0;

                    for (k = i + 1; k < 15; k++)
                    {
                        if (frame[j] == page[k])
                        {
                            next = k;
                            break;
                        }
                    }

                    if (next == 0)
                    {
                        pos = j;
                        break;
                    }

                    if (next > far)
                    {
                        far = next;
                        pos = j;
                    }
                }

                frame[pos] = page[i];
            }
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
