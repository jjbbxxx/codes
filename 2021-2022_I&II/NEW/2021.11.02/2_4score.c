//一个学习小组有5个人，每个人有3门课的考试成绩，输出每门课的平均成绩，
//计算每人的平均成绩并按照降序输出。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    float a[5][4], num;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            num = rand() % 10 + 85;
            a[i][j] = num;
        }
    }
    for(int i=0;i<5;i++){
        a[i][3]=(a[i][0]+a[i][1]+a[i][2])/3;
    }
    for(int i=0;i<5;i++){
        printf("%d: ",i+1);
        for(int j=0;j<4;j++){
            printf("%5.2f ",a[i][j]);
        }
        printf("\n");
    }
    float b[5];
    for(int i=0;i<5;i++){
        b[i]=a[i][3];
    }
    int f=0;
    float temp;
    for (int i = 0; i < 5; i++)
    {
        f = i;
        for (int n = i; n < 5; n++)
        {
            if (b[n] > b[f])
                f = n;
        }
        temp = b[i];
        b[i] = b[f];
        b[f] = temp;
    }
    printf("range:\n");
    for(int i=0;i<5;i++){
        printf("%.2f ",b[i]);
    }
    printf("\n");
    return 0;
}