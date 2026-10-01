#include <stdio.h>

int main()
{
    int n, a[7], head;
    int i, j, temp, total = 0;

    printf("Enter total number of disk blocks: ");
    scanf("%d", &n);

    printf("Enter disk request string: ");
    for (i = 0; i < 7; i++)
        scanf("%d", &a[i]);

    printf("Enter current head position: ");
    scanf("%d", &head);

    /* Sort */
    for (i = 0; i < 7; i++)
    {
        for (j = i + 1; j < 7; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nLOOK Order:\n");
    printf("%d", head);

    /* Left */
    for (i = 6; i >= 0; i--)
    {
        if (a[i] < head)
        {
            total += head - a[i];
            head = a[i];
            printf(" -> %d", head);
        }
    }

    /* Right */
    for (i = 0; i < 7; i++)
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
