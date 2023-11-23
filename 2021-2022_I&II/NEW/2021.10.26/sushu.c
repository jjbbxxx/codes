#include<stdio.h>
int main(){
    int n,m;
    start:
    printf("请输入n,m(n<m)：");
    scanf("%d %d",&n,&m);
    if(n>=m){
        printf("输入的数据有误!\n");
        goto start;
    }
    int a=n,count=0;
    while(a<=m){
    int t=0,i;
    for(i=1;i<a;i++){
        if (a%i==0)t=i;
    }
    if(t==1){
        printf("%d ",a);
        count++;
    }
    a++;
    }
    printf("\n%d~%d间共有%d个素数。\n",n,m,count);
    return 0;
}
