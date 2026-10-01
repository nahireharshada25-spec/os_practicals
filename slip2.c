#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, head, total = 0;
    int request[100];

    printf("Enter total number of disk blocks: ");
    scanf("%d", &n);

    printf("Enter number of disk requests: ");
    scanf("%d", &i);

    printf("Enter disk request string:\n");

    int count = i;

    for (i = 0; i < count; i++)
        scanf("%d", &request[i]);

    printf("Enter current head position: ");
    scanf("%d", &head);

    printf("\nFCFS Order:\n");
    printf("%d", head);

    for (i = 0; i < count; i++)
    {
        total = total + abs(head - request[i]);
        head = request[i];

        printf(" -> %d", request[i]);
    }

    printf("\n\nTotal Head Movement = %d\n", total);

    return 0;
}
