/*大数求和问题。*/
#include <stdio.h>
#include <string.h>

void convert(char *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        *(p + i) -= '0';
    }
}

void add(char *p, int len1, int len2)
{
    for (int i = len1 - 1; i >= 0; i--)
    {
        *(p + i + (len2 - len1)) = *(p + i);
    }

    for (int i = 0; i < len2 - len1; i++)
    {
        *(p + i) = 0;
    }
}

int main()
{
    int len1, len2, len3, c[1001] = {0}, f = 0;
    char a[1000], b[1000];

    printf("input 2 numbers:\n");
    gets(a);
    gets(b);
    len1 = strlen(a);
    len2 = strlen(b);
    convert(a, len1);
    convert(b, len2);
    if (len1 > len2)
    {
        len3 = len1;
        add(b, len2, len1);
    }
    else
    {
        len3 = len2;
        add(a, len1, len2);
    }
    for (int i = 0; i < len3; i++)
    {
        c[i + 1] = a[i] + b[i];
    }
    for (int i = 0; i < len3; i++)
    {
        if (c[i + 1] > 9)
        {
            c[i] += c[i + 1] / 10;
            c[i + 1] %= 10;
        }
    }



    printf("ans:");
    int t = 0;
    while (1)
    {
        if (c[t++])
            break;
        else
            f++;
    }
    for (int i = f; i < len3 + 1; i++)
    {
        printf("%d", c[i]);
    }
    return 0;
}
