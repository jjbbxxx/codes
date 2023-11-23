/*
(1)利用数组计算并保存Fibonacci数列的前20项.
(2)验证F（n）/F（n-1）是否接近黄金分割数（0.618）。
*/
#include <stdio.h>
int main()
{
    float a[20];
    a[0] = 0;
    a[1] = 1;
    int i;
    for (i = 2; i <= 19; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    for (i = 0; i <= 19; i++)
    {
        printf("%.0f ", a[i]);
    }
    printf("\n");
    for(int i=2;i<20-1;i++){
        printf("%.6f\n",a[i]/a[i+1]);
    }
    return 0;
}
