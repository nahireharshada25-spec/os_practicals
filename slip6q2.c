#include <stdio.h>

int main()
{
    int n, a[20], head, i, j, temp, total = 0;

    printf("Enter total number of disk blocks: ");
    scanf("%d", &n);

    printf("Enter disk request string: ");
    for (i = 0; i < 8; i++)
        scanf("%d", &a[i]);

    printf("Enter current head position: ");
    scanf("%d", &head);

    /* Sort requests */
    for (i = 0; i < 8; i++)
    {
        for (j = i + 1; j < 8; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nC-SCAN Order:\n");
    printf("%d", head);

    for (i = 0; i < 8; i++)
    {
        if (a[i] >= head)
        {
            total += a[i] - head;
            head = a[i];
            printf(" -> %d", head);
        }
    }

    total += n - 1 - head;
    head = n - 1;
    printf(" -> %d", head);

    total += n - 1;
    head = 0;
    printf(" -> %d", head);

    for (i = 0; i < 8; i++)
    {
        if (a[i] < 100)
        {
            total += a[i] - head;
            head = a[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}
