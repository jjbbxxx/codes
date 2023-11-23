#include <stdio.h>

int main()
{
    int x = 0;
    int y, m, d, y1, y2, m1, m2, d1, d2, yjg, dmax, err = 0;
    while (x == 0)
    {
        printf("请输入年月日：\n");
        scanf("%d %d %d", &y, &m, &d);
        if (y % 4 != 0)
            yjg = 0;
        else if (y % 100 == 0 && y % 400 != 0)
            yjg = 0;
        else
            yjg = 1;
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 | m == 12)
            dmax = 31;
        else if (m == 4 || m == 6 || m == 9 || m == 11)
            dmax = 30;
        else if (m == 2 && yjg == 0)
            dmax = 28;
        else if (m == 2 && yjg == 1)
            dmax = 29;
        else
            err = 1;
        if (d > dmax)
            err = 1;
        if (err == 1)
            printf("输入的日期有问题，请检查！\n");
        else
            x = 1;
    }
    if (d != dmax)
    {
        d2 = d + 1;
        m2 = m;
        y2 = y;
    }
    else
    {
        d2 = 1;
        if (m + 1 != 12)
        {
            m2 = m + 1;
            y2 = y;
        }
        else
        {
            m2 = 1;
            y2 = y + 1;
        }
    }
    if (d != 1)
    {
        d1 = d - 1;
        m1 = m;
        y1 = y;
    }
    else if (m - 1 == 0)
    {
        d1 = 31;
        m1 = 12;
        y1 = y - 1;
    }
    else if (m - 1 != 0)
    {
        m--;
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 | m == 12)
            dmax = 31;
        else if (m == 4 || m == 6 || m == 9 || m == 11)
            dmax = 30;
        else if (m == 2 && yjg == 0)
            dmax = 28;
        else if (m == 2 && yjg == 1)
            dmax = 29;
        d1 = dmax;
        m1 = m;
        y1 = y;
    }
    printf("前一天为%d年%d月%d日\n后一天为%d年%d月%d日\n", y1, m1, d1, y2, m2, d2);

    return 0;
}
