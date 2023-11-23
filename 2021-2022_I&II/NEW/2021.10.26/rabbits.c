#include <stdio.h>
int main()
{
    int a[20];
    a[0] = 0;
    a[1] = 1;
    int i;
    for (i = 2; i <= 20; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    for (i = 0; i <= 7; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (i = 8; i <= 15; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (i = 16; i <= 19; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
