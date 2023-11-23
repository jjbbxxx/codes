/*7、	编写函数，用指针操作实现字符串的复制，不能使用库函数strcpy
int strCopy( char* pStr1, int n, char* pStr2);
注意检测pStr1指向的长度为n的字符数组有足够的空间存放字符串pStr2，
若存整的字符串pStr2，则不进行复制，函数返回0。
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