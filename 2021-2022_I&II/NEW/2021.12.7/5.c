/*一个学习小组有若干学生（人数n在运行时输入，定义动态数组），
输入每个人的平均成绩， 并按照一定顺序输出。
void selectSort( float* grade, int n, int type); //选择排序,type>0升序,type<降序
void print( float* f,  int n);/输出长度为n的浮点型数组
*/
#include <stdio.h>
#include <stdlib.h>

void selectSort(float *grade, int n, int type)
{
    int temp = 0;
    if (type > 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (*(grade + i) > *(grade + j))
                {
                    temp = *(grade + j);
                    *(grade + j) = *(grade + i);
                    *(grade + i) = temp;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (*(grade + i) < *(grade + j))
                {
                    temp = *(grade + j);
                    *(grade + j) = *(grade + i);
                    *(grade + i) = temp;
                }
            }
        }
    }
}
void print(float *f, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.1f ", *(f + i));
    }
}
int main()
{
    float *p;
    int n;
    printf("input n:");
    scanf("%d", &n);
    p = (float *)malloc(n * sizeof(float));
    printf("input n scores:");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", p + i);
    }
    selectSort(p, n, 1);
    print(p, n);
    printf("\n");
    selectSort(p, n, -1);
    print(p, n);
    free(p)
    return 0;
}