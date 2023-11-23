#include <stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int a[10001];
    int temp, f = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < N; i++)
    {
        f = i;
        for (int n = i; n < N; n++)
        {
            if (a[n] < a[f])
                f = n;
        }
        temp = a[i];
        a[i] = a[f];
        a[f] = temp;
    }
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}