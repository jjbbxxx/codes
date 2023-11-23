//输出杨辉三角形前10行。
#include<stdio.h>
int main(){
    int a[10][10]={};
    for(int i=0;i<10;i++){
        a[i][0]=1;
    }
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(a[i][j]!=0)
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}