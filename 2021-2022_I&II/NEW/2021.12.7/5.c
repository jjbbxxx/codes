/*һ��ѧϰС��������ѧ��������n������ʱ���룬���嶯̬���飩��
����ÿ���˵�ƽ���ɼ��� ������һ��˳�������
void selectSort( float* grade, int n, int type); //ѡ������,type>0����,type<����
void print( float* f,  int n);/�������Ϊn�ĸ���������
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