#include <stdio.h>

int main()
{
    int pages[] = {8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2};
    int frame[3] = {-1, -1, -1};
    int count[3] = {0, 0, 0};
    int fault = 0;
    int i, j, k, max, pos, found;

    printf("Page\tFrames\t\tStatus\n");

    for (i = 0; i < 15; i++)
    {
        found = 0;

        for (j = 0; j < 3; j++)
        {
            if (frame[j] == pages[i])
            {
                found = 1;
                count[j]++;
            }
        }

        if (found == 0)
        {
            fault++;

            pos = -1;

            for (j = 0; j < 3; j++)
            {
                if (frame[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
            {
                max = count[0];
                pos = 0;

                for (k = 1; k < 3; k++)
                {
                    if (count[k] > max)
                    {
                        max = count[k];
                        pos = k;
                    }
                }
            }

            frame[pos] = pages[i];
            count[pos] = 1;
        }

        printf("%d\t", pages[i]);

        for (j = 0; j < 3; j++)
            printf("%d ", frame[j]);

        if (found)
            printf("\tHit\n");
        else
            printf("\tPage Fault\n");
    }

    printf("\nTotal Page Faults = %d\n", fault);

    return 0;
}
