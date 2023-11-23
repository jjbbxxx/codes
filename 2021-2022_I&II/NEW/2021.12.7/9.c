/*9、	编写函数实现在字符串pStr中查找子串pSub 
int subString( char* pStr,  char* pSub); //计算字符串中子串出现的次数。
char* subString( char* pStr,  char* pSub); //返回查找到第一个子串的地址
*/
#include <stdio.h>
int subString(char *pStr, char *pSub)
{
    int len1 = 0, len2 = 0, count = 0;
    for (int i = 0;; i++)
    {
        if (*(pStr + i) != '\0')
            len1++;
        else
            break;
    }
    for (int i = 0;; i++)
    {
        if (*(pSub + i) != '\0')
            len2++;
        else
            break;
    }

    for (int i = 0; i < len1; i++)
    {
        if (*(pStr + i) == *pSub)
        {
            for (int j = 1; j < len2; j++)
            {
                if (*(pStr + i + j) != *(pSub + j))
                {
                    break;
                }
                count++;
            }
        }
    }
    return count;
}

char *subStringadd(char *pStr, char *pSub)
{
    int len1 = 0, len2 = 0;
    for (int i = 0;; i++)
    {
        if (*(pStr + i) != '\0')
            len1++;
        else
            break;
    }
    for (int i = 0;; i++)
    {
        if (*(pSub + i) != '\0')
            len2++;
        else
            break;
    }

    char *add = pStr;
    for (int i = 0; i < len1; i++)
    {
        if (*(pStr + i) == *pSub)
        {
            for (int j = 1; j < len2; j++)
            {
                if (*(pStr + i + j) != *(pSub + j))
                {
                    break;
                }
                add += i;
                return add;
            }
        }
    }
    return "none";
}

int main()
{
    char *str = "hellohellohehehe", *sub1 = "he", *sub2 = "ll";
    printf("%s:%d:%x\n", sub1, subString(str, sub1), subStringadd(str, sub1));
    printf("%s:%d:%x\n", sub2, subString(str, sub2), subStringadd(str, sub2));
    return 0;
}