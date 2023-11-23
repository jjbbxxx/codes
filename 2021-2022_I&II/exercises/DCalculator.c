#include <stdio.h>
#include <stdlib.h>
int fun(int a)
{
    int result = 1;
    for (int t = a; t > 1; t--)
    {
        result *= t;
    }
    return result;
}

int calc(int **a, int n)
{
    if (n == 1)
        return a[0][0];
    if (n == 2)
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    int add, sum = 0;
    for (int i = 0; i < n; i++)
    {
        add = 1;
        for (int u = 0; u < n; u++)
        {
            if (i + u < n)
                add *= a[u][i + u];
            else
                add *= a[u][i + u - n];
        }
        sum += add;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        add = 1;
        for (int u = 0; u < n; u++)
        {
            if (i - u >= 0)
                add *= a[u][i - u];
            else
                add *= a[u][i - u + n];
        }
        sum -= add;
    }
    return sum;
}
void output(int **p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
        {
            printf("%4d", p[i][j]);
        }
        printf("    |");
        printf("\n");
    }
}
void input(int **p, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of rows:");
    scanf("%d", &n);
    int **p = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        p[i] = malloc(n * sizeof(int));
    input(p, n);
    output(p, n);
    printf("result=%d \n", calc(p, n));
    return 0;
}