/*8��	��д����ʵ���ַ���������, ��pStr2���ӵ�pStr1��
int strConnect( char * pStr1, int n, char* pStr2);
ע����pStr1ָ��ĳ���Ϊn���ַ��������㹻�Ŀռ����ַ���pStr2��
����pStr2�ַ����ĳ��ȣ������ܴ�����Ӻ��������´�����������0��
*/
#include <stdio.h>
int strConnect(char *pStr1, int n, char *pStr2)
{
    int len1 = 0, len2 = 0;
        for (int i = 0;; i++)
    {
        if (*(pStr1 + i) != '\0')
            len1++;
        else
            break;
    }
    for (int i = 0;; i++)
    {
        if (*(pStr2 + i) != '\0')
            len2++;
        else
            break;
    }
    if (n - len1 < len2)
        return 0;
    else
    {
        for (int i = 0; i < len2; i++)
        {
            *(pStr1 + len1 + i) = *(pStr2 + i);
        }
        return 1;
    }
}
int main()
{
    char a[10]="hello",*b="good",*c="hahahahahahaha";
    printf("%d \n%d %s",strConnect(a,10,c),strConnect(a,10,b),a);
    return 0;
}