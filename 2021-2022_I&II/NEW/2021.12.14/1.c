#include <stdio.h>
struct date
{
    int year, month, day;
};
int jdgy(int y)
{
    if (y % 4 != 0)
        return 0;
    else if (y % 100 == 0 && y % 400 != 0)
        return 0;
    else
        return 1;
}
int cal(struct date a)
{
    if (a.year > 2021 || a.month > 12 || a.day > 31)
        return -1;
    if (a.year == 2021 && a.month == 2 && a.day > 28)
        return -1;
    int sum = 0;
    for (int i = a.year; i < 2021; i++)
    {
        if (jdgy(i) == 1)
        {
            if (a.day > 29)
                return -1;
            sum += 366;
        }
        else
        {
            if (a.day > 28)
                return -1;
            sum += 365;
        }
    }
    if (a.month != 12)
    {
        for (int i = a.month + 1; i <= 12; i++)
        {
            if (i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                sum += 31;
            else if (i == 4 || i == 6 || i == 9 || i == 11)
            {
                if (a.day > 30)
                    return -1;
                sum += 30;
            }
            else
                sum += 28;
        }
    }
    sum += 31 - a.day;
    return sum + 1;
}
int main()
{
    struct date test;
    int ans = -1;
    while (ans < 0)
    {
        printf("input a date:\n");
        scanf("%d %d %d", &test.year, &test.month, &test.day);
        ans = cal(test);
        if (ans > 0)
            break;
        printf("err!\n");
    }
    printf("%d day(s) left:)\n", ans);
    return 0;
}