/*随机产生6个数字，与用户输入的数字进行比较，
输它们相同的数字个数（使用动态内存分配）。*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count(int *a, int *b)
{
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (*(a + i) == *(b + j))
            {
                *(b + j) = 0;
                sum++;
            }
        }
    }
    return sum;
}
int main()
{
    srand((unsigned)time(NULL));
    int a[6], b[6];
    for (int i = 0; i < 6; i++)
    {
        a[i] = rand() % 10 + 1;
    }
    printf("input 6 numbers(1-10):");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &b[i]);
    }
    int *key=a,*ans=b;
    printf("prize:");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n%d correct number(s).\n", count(key, ans));
    return 0;
}