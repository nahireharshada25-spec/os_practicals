#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, count, head;
    int a[100], visited[100] = {0};
    int i, j, min, pos, d, total = 0;

    printf("Enter total number of disk blocks: ");
    scanf("%d", &n);

    printf("Enter number of requests: ");
    scanf("%d", &count);

    printf("Enter disk request string: ");
    for (i = 0; i < count; i++)
        scanf("%d", &a[i]);

    printf("Enter current head position: ");
    scanf("%d", &head);

    printf("\nSSTF Order:\n");
    printf("%d", head);

    for (i = 0; i < count; i++)
    {
        min = 9999;

        for (j = 0; j < count; j++)
        {
            if (visited[j] == 0)
            {
                d = abs(head - a[j]);

                if (d < min)
                {
                    min = d;
                    pos = j;
                }
            }
        }

        visited[pos] = 1;
        total = total + min;
        head = a[pos];

        printf(" -> %d", head);
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}
