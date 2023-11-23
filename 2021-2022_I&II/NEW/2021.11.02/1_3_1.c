//—°‘Ò≈≈–Ú£¨Ωµ–Ú
#include <stdio.h>
int main()
{
    int a[8];
    int temp, f = 0;
    printf("input 8 numbers:");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 8; i++)
    {
        f = i;
        for (int n = i; n < 8; n++)
        {
            if (a[n] > a[f])
                f = n;
        }
        temp = a[i];
        a[i] = a[f];
        a[f] = temp;
    }
    printf("result:\n");
    for (int i = 0; i < 8; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}