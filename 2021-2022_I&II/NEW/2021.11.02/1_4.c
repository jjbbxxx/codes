//将两个从小到大有序整型数组a和b合并出一个有序整数数组c。
#include <stdio.h>
int main()
{
    int a[5], b[5], c[10], i, k, m = 0, n = 0, p;
    printf("input 5 numbers for array A(from small to big):");
    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);
    printf("input 5 numbers for array B(from small to big):");
    for (i = 0; i < 5; i++)
        scanf("%d", &b[i]);
    for (k = 0; k < 10; k++)
    {
        if (a[m] <= b[n])
        {
            c[k] = a[m];
            m += 1;
        }
        else
        {
            c[k] = b[n];
            n += 1;
        }
    }
    for (p = 0; p < 10; p++)
        printf("%d ", c[p]);
    return 0;
}
