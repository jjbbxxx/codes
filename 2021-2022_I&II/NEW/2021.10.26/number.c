#include <stdio.h>
int main()
{
    int a, b, c, count = 0;
    for (a = 1; a <= 4; a++)
    {
        for (b = 1; b <= 4; b++)
        {
            for (c = 1; c <= 4; c++)
            {
                if (a != c && a != b && b != c)
                {
                    printf("%d%d%d ", a, b, c);
                    count++;
                }
            }
        }
    }
    printf("\n¹²%d¸ö¡£\n", count);
    return 0;
}