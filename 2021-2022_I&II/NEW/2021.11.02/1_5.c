/*
��һ���������ظ�Ԫ��ȥ��, �����������д洢, ���������ʣ���Ԫ�ؼ�����Ŀ��
����,��������a[12]={1,1,2,7,3,2,3,4,5,8,7,4}�����ʣ��7�����ݣ�1,2,7,3,4,5,8��
*/
#include <stdio.h>
int main()
{
    int a[20], sum = 0;
    printf("input 20 numbers:\n");
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 20; i++)
    {
        for (int n = i + 1; n < 20; n++)
        {
            if (a[n] == a[i])
            {
                a[n] = -1;
            }
        }
        if (a[i] != -1)
        {
            printf("%d ", a[i]);
            sum += 1;
        }
    }
    printf("\nsum=%d\n", sum);
    return 0;
}