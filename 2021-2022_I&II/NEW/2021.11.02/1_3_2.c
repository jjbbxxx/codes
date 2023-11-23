//√∞≈›≈≈–Ú£¨Ωµ–Ú
#include <stdio.h>
int main()
{
    int a[8];
    int temp;
    printf("input 8 numbers:");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 7; i >= 0; i--)
    {
        for (int n = 0; n <= i - 1; n++)
        {
            if (a[n] < a[n + 1])
            {
                temp = a[n];
                a[n] = a[n + 1];
                a[n + 1] = temp;
            }
        }
    }
    printf("result:\n");
    for (int i = 0; i < 8; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}