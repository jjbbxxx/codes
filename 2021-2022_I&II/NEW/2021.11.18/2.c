/*
��д������֤��°ͺղ��룺 
һ����С��6��ż�����Ա�ʾ����������֮�͡�
��6��3��3��8��3��5��10��3��7������ 
��������������һ������6��ż��n��
����34�����������ʽ��34��3��31��
���������Ҫ���������������
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