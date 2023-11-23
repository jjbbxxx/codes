/*随机产生20个不大于10的自然数，
将其存储在一个二维数组中，
且偶数与奇数分别存储在不同列上。
输出该数组并统计偶数与奇数的个数。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a[20], num;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 20; i++)
    {
        num = rand() % 10 + 1;
        a[i] = num;
    }
    int b[2][20] = {};
    for (int i = 0; i < 20; i++)
    {
        if (a[i] % 2 == 1)
            b[0][i] = a[i];
        else
            b[1][i] = a[i];
    }
    int sum1 = 0, sum2 = 0;
    printf("奇数：");
    for (int i = 1; i < 20; i++)
    {
        if (b[0][i] != 0)
        {
            printf("%d ", b[0][i]);
            sum1++;
        }
    }
    printf("共%d个\n", sum1);

    printf("偶数：");
    for (int i = 1; i < 20; i++)
    {
        if (b[1][i] != 0)
        {
            printf("%d ", b[1][i]);
            sum2++;
        }
    }
    printf("共%d个\n", sum2);
    return 0;
}
