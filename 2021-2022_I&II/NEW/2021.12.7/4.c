/*
n个学生参加期末考试，每人有3门课程的成绩.
设计函数对统计成绩每人的平均分，在主函数中输出清晰地成绩列表。
void average( float ( * score)[3], int n, float * ave); 
// 平均成绩存储在float a[n]
*/
#include <stdio.h>
void average(float (*score)[3], int n, float *ave)
{
    *ave = (*(*score) + *(*score + 1) + *(*score + 2)) / 3;
}
int main()
{
    float a[3];
    float *p = a;
    float scr[3][3] = {{84, 97, 85}, {75, 81, 80}, {80, 90, 88}};
    for (int i = 0; i < 3; i++)
        average(scr + i, 3, p + i);
    for (int i = 0; i < 3; i++)
    {
        printf("student%d:  ",i+1);
        for (int j = 0; j < 3; j++)
        {
            printf("%3.0f ", scr[i][j]);
        }
        printf("  %.1f ", a[i]);
        printf("\n");
    }

    return 0;
}