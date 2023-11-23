/*8、	编写函数实现字符串的连接, 将pStr2连接到pStr1后
int strConnect( char * pStr1, int n, char* pStr2);
注意检测pStr1指向的长度为n的字符数组有足够的空间存放字符串pStr2，
计算pStr2字符串的长度，若不能存放连接后完整的新串，则函数返回0。
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