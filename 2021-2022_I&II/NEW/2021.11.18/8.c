//��д���� void inverse( int arr[ ][N] ) ��ʵ��N*N�ľ���ת�ò���, ����NΪ������
#include <stdio.h>
#define N 3
void inverse(int a[][N])
{
    int i, j;
    int t;
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
    }
}
int main()
{
    int a[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    inverse(a);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%2d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
