/*7��	��д��������ָ�����ʵ���ַ����ĸ��ƣ�����ʹ�ÿ⺯��strcpy
int strCopy( char* pStr1, int n, char* pStr2);
ע����pStr1ָ��ĳ���Ϊn���ַ��������㹻�Ŀռ����ַ���pStr2��
���������ַ���pStr2���򲻽��и��ƣ���������0��
*/
#include <stdio.h>
int strCopy(char *pStr1, int n, char *pStr2)
{
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        if (*(pStr2 + i) != '\0')
            count++;
        else
            break;
    }
    if (n < count)
        return 0;
    else
    {
        for (int i = 0; i < count; i++)
        {
            *(pStr1 + i) = *(pStr2 + i);
        }
        return 1;
    }
}
int main()
{
    char *a = "pointerpointer!!!", b[5], c[20];
    printf("%d %s\n", strCopy(b, 5, a),b);
    printf("%d %s\n", strCopy(c, 20, a),c);
    return 0;
}