/*�������20��������10����Ȼ����
����洢��һ����ά�����У�
��ż���������ֱ�洢�ڲ�ͬ���ϡ�
��������鲢ͳ��ż���������ĸ�����
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
    printf("������");
    for (int i = 1; i < 20; i++)
    {
        if (b[0][i] != 0)
        {
            printf("%d ", b[0][i]);
            sum1++;
        }
    }
    printf("��%d��\n", sum1);

    printf("ż����");
    for (int i = 1; i < 20; i++)
    {
        if (b[1][i] != 0)
        {
            printf("%d ", b[1][i]);
            sum2++;
        }
    }
    printf("��%d��\n", sum2);
    return 0;
}
