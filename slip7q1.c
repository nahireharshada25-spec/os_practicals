#include <stdio.h>

int main()
{
    int alloc[5][4] = {
        {2, 0, 0, 1},
        {3, 1, 2, 1},
        {2, 1, 0, 3},
        {1, 3, 1, 2},
        {1, 4, 3, 2}};

    int max[5][4] = {
        {4, 2, 1, 2},
        {5, 2, 5, 2},
        {2, 3, 1, 6},
        {1, 4, 2, 4},
        {3, 6, 6, 5}};

    int avail[4] = {3, 3, 2, 1};
    int need[5][4];
    int finish[5] = {0};
    int i, j, k, count = 0;

    for (i = 0; i < 5; i++)
        for (j = 0; j < 4; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("Need Matrix:\n");

    for (i = 0; i < 5; i++)
    {
        printf("P%d: ", i);
        for (j = 0; j < 4; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    printf("\nAvailable: 3 3 2 1");
    printf("\nSafe Sequence: ");

    while (count < 5)
    {
        for (i = 0; i < 5; i++)
        {
            if (finish[i] == 0)
            {
                for (j = 0; j < 4; j++)
                    if (need[i][j] > avail[j])
                        break;

                if (j == 4)
                {
                    printf("P%d ", i);

                    for (k = 0; k < 4; k++)
                        avail[k] += alloc[i][k];

                    finish[i] = 1;
                    count++;
                }
            }
        }
    }

    printf("\nSystem is in SAFE STATE");

    return 0;
}
