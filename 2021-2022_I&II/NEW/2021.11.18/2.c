/*
编写程序验证歌德巴赫猜想： 
一个不小于6的偶数可以表示成两个素数之和。
如6＝3＋3，8＝3＋5，10＝3＋7，…… 
在主函数中输入一个大于6的偶数n，
例如34，输出如下形式：34＝3＋31。
输出不满足要求的数则重新输入
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
    int a, b, num;
start:
    printf("input a even number (num>6):");
    scanf("%d", &num);
    if (num % 2 != 0 || num <= 6)
    {
        printf("err!\n");
        goto start;
    }
    else
    {
        printf("%d", num);
        for (int i = num - 1; i >= num - i; i--)
        {
            if (prime(i) == 1 && prime(num - i) == 1)
            {
                b = i;
                a = num - i;
                printf("=%d+%d", a, b);
            }
        }
    }
    printf("\n");
    return 0;
}