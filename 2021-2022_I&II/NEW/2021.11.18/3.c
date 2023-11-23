/*一个整数的所有因子（包括1，但不包括本身）
之和等于该数，则该数称为完数。
例如6是一个完数，因为6=1+2+3。 
编写一个isPerfectnum函数，判断参数number是否为完数。
利用该函数判断并打印1到1000之间的所有完数。
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