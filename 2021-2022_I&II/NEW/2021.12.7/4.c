/*
n��ѧ���μ���ĩ���ԣ�ÿ����3�ſγ̵ĳɼ�.
��ƺ�����ͳ�Ƴɼ�ÿ�˵�ƽ���֣�������������������سɼ��б�
void average( float ( * score)[3], int n, float * ave); 
// ƽ���ɼ��洢��float a[n]
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