/*
��д�ж������ĺ���, �������������ã����n~m֮�������������
	int prime ( int m ) ;   // ��mΪ�����򷵻�1�����򷵻�0
*/
#include <stdio.h>
int prime(int m)
{
    for (int i = 2; i < m; i++)
    {
        if (m % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int n, m;
    printf("input n m:\n");
    scanf("%d %d", &n, &m);
    for (int i = n; i <= m; i++)
    {
        if (prime(i) == 1)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}