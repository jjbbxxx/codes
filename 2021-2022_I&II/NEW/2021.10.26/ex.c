#include <stdio.h>
#include <math.h>
int main()
{
    double r = 1, a;
    float x;
    printf("input x:");
    scanf("%f", &x);
    int n = 1;
    while (n <= 10)
    {
        int b = 1;
        for (int i = n; i >= 1; i--)
        {
            b *= i;
        }
        a = (pow(x, n)) / b;
        r += a;
        n += 1;
    }
    printf("e^%.2f=%.2f", x, r);
    return 0;
}