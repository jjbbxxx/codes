/*һ���������������ӣ�����1��������������
֮�͵��ڸ������������Ϊ������
����6��һ����������Ϊ6=1+2+3�� 
��дһ��isPerfectnum�������жϲ���number�Ƿ�Ϊ������
���øú����жϲ���ӡ1��1000֮�������������
*/
#include <stdio.h>
int isperfectnum(int a)
{
    int i = 2, sum = 0;

    while (i < a)
    {
        if (a % i == 0)
        sum += i;
        i++;
    }
    if (sum + 1 == a)
        return 1;
    else
        return 0;
}
int main()
{
    for (int j = 1; j <= 1000; j++)
    {
        if (isperfectnum(j) == 1)
        {
            printf("%d ", j);
        }
    }
    return 0;
}