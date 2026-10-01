#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, head, i, j, temp, total = 0;
    int a[20];

    printf("Enter total number of disk blocks: ");
    scanf("%d", &n);

    printf("Enter number of requests: ");
    scanf("%d", &m);

    printf("Enter disk request string: ");
    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);

    printf("Enter current head position: ");
    scanf("%d", &head);

    /* Sort */
    for (i = 0; i < m; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Direction: Left\n");
    printf("\nSCAN Order:\n%d", head);

    /* Left side */
    for (i = m - 1; i >= 0; i--)
    {
        if (a[i] < head)
        {
            total += head - a[i];
            head = a[i];
            printf(" -> %d", head);
        }
    }

    /* Go to 0 */
    total += head;
    head = 0;
    printf(" -> 0");

    /* Right side */
    for (i = 0; i < m; i++)
    {
        if (a[i] > head)
        {
            total += a[i] - head;
            head = a[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}
