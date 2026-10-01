#include <stdio.h>

int main()
{
    int allocation[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 3},
        {2, 1, 1},
        {0, 0, 2}};

    int max[5][3] = {
        {0, 0, 0},
        {2, 0, 2},
        {0, 0, 0},
        {1, 0, 0},
        {0, 0, 2}};

    int need[5][3], available[3];
    int i, j, choice;

    for (i = 0; i < 5; i++)
        for (j = 0; j < 3; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    do
    {
        printf("\n1. Accept Available");
        printf("\n2. Display Allocation, Max");
        printf("\n3. Display Need");
        printf("\n4. Display Available");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter A B C: ");
            scanf("%d%d%d", &available[0], &available[1], &available[2]);
        }

        else if (choice == 2)
        {
            printf("\nAllocation:\n");
            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 3; j++)
                    printf("%d ", allocation[i][j]);
                printf("\n");
            }

            printf("\nMax:\n");
            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 3; j++)
                    printf("%d ", max[i][j]);
                printf("\n");
            }
        }

        else if (choice == 3)
        {
            printf("\nNeed:\n");
            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 3; j++)
                    printf("%d ", need[i][j]);
                printf("\n");
            }
        }

        else if (choice == 4)
        {
            printf("\nAvailable: %d %d %d\n",
                   available[0], available[1], available[2]);
        }

    } while (choice != 5);

    return 0;
}
