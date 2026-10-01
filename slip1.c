#include <stdio.h>

int main()
{
    int allocation[5][3] = {
        {2,3,2},
        {4,0,0},
        {5,0,4},
        {4,3,3},
        {2,2,4}
    };

    int max[5][3] = {
        {9,7,5},
        {5,2,2},
        {1,0,4},
        {4,4,4},
        {6,5,5}
    };

    int available[3] = {3,3,2};
    int need[5][3];
    int i,j,choice;

    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    do
    {
        printf("\n--- BANKER'S ALGORITHM ---\n");
        printf("1. Accept Available\n");
        printf("2. Display Allocation and Max\n");
        printf("3. Display Need Matrix\n");
        printf("4. Display Available\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter Available A B C: ");
                scanf("%d%d%d",
                      &available[0],
                      &available[1],
                      &available[2]);
                break;

            case 2:
                printf("\nAllocation\tMax\n");

                for(i=0;i<5;i++)
                {
                    printf("P%d\t%d %d %d\t\t%d %d %d\n",
                           i,
                           allocation[i][0],
                           allocation[i][1],
                           allocation[i][2],
                           max[i][0],
                           max[i][1],
                           max[i][2]);
                }
                break;

            case 3:
                printf("\nNeed Matrix:\n");

                for(i=0;i<5;i++)
                {
                    printf("P%d : ",i);

                    for(j=0;j<3;j++)
                        printf("%d ",need[i][j]);

                    printf("\n");
                }
                break;

            case 4:
                printf("\nAvailable: %d %d %d\n",
                       available[0],
                       available[1],
                       available[2]);
                break;

            case 5:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 5);

    return 0;
}
