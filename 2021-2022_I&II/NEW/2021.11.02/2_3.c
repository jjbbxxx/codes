
//找出二维数组中的所有鞍点，既该位置的元素在该行上最大，但是在该列上最小。也有可能没有鞍点。
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a[5][5], num;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            num = rand() % 100 + 1;
            a[i][j] = num;
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    int max, t1, t2, f, count = 0;
    printf("points: ");
    for (int i = 0; i < 5; i++)
    {
        max = a[i][0];
        for (int j = 0; j < 5; j++)
        {
            if (max < a[i][j])
            {
                max = a[i][j];
                t1 = i;
                t2 = j;
                f = 1;
            }
        }
        for (int k = 0; k < 5; k++)
        {
            if (max < a[k][t2])
            {
                f = 0;
                break;
            }
        }
        if (f == 1)
        {
            printf("[%d][%d]=%d ", t1, t2, max);
            count++;
        }
    }
    if (count == 0)
        printf("NO!\n");
        printf("\n");
    return 0;
}