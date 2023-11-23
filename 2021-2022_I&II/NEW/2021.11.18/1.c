/*
编写判断素数的函数, 并用主函数调用，输出n~m之间的所有素数。
	int prime ( int m ) ;   // 若m为素数则返回1，否则返回0
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