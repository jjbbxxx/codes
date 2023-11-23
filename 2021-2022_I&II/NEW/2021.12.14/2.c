#include <stdio.h>
struct date
{
    int year;
    int month;
    int day;
};
struct employee
{
    int num;
    char *name;
    struct date bday;
    float mny;
} epe[3] = {
    {1, "haha", 2002, 5, 9, 8000},
    {2, "hehe", 2003, 7, 30, 3000},
    {3, "hoho", 2003, 12, 3, 4200}};
void print(struct employee *epe, int n)
{
    printf("%d\t%s\t%d.%d.%d\t%.1f\n", epe[n].num, epe[n].name, epe[n].bday.year, epe[n].bday.month, epe[n].bday.day, epe[n].mny);
}
float avgmny(struct employee *a, int n)
{
    float avg, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (a[i].mny);
    }
    avg = sum / n;
    return avg;
}
void best(struct employee *b, int n)
{
    int f = 0;
    for (int i = 0; i < n; i++)
        if (b[i].mny > b[f].mny)
            f = i;
    print(b, f);
}
void sort(struct employee *c, int n)
{
    struct employee temp;
    for (int i = 3 - 1; i > 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (((c + j)->mny) < ((c + j + 1)->mny))
            {
                temp = *(c + j);
                *(c + j) = *(c + j + 1);
                *(c + j + 1) = temp;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        print(c, i);
    }
}
int main()
{
    printf("average salary is: %.1f\n", avgmny(epe, 3));
    printf("The highest salary belongs to: \n");
    best(epe, 3);
    printf("employee information:\nnum\tname\tbirthday\tsalary\n");
    sort(epe, 3);
    return 0;
}