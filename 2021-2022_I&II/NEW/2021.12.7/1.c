/*1��	��ָ�뷽��ʵ������ķ�ת��������º��������
void invert1 ( int * a , int len);  //һά�������ת
void invert2 ( int (* a)[N] );  //��N*N�ľ����ԶԽ���Ϊ�ᷭת�������Խ��ߣ�
*/
#include <stdio.h>
#define N 3
void invert1(int *a, int len)
{
    int temp[len];
    for (int i = 0; i < len; i++)
    {
        temp[i] = a[i];
    }
    for (int i = 0; i < len; i++)
    {
        *(a + i) = temp[len - i - 1];
    }
}
void invert2(int (*a)[N])
{
    int temp[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp[i][j] =*(*a+j);
        }
        a+=1;
    }
    a-=N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            *(*a+j)=temp[j][i];
        }
        a+=1;
    }
}
int main()
{
    int a[5] = {1, 2, 3, 4, 5}, b[N][N] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    invert1(a, 5);
    invert2(b);
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
        printf("\n");
 for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}