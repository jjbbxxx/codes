#include<stdio.h>
int main(){
    int m,n;
    printf("请输入两个正整数：");
    scanf("%d %d",&m,&n);
    printf("method1:\n");
    int r1,min;
    if(m<n)min=m;else min=n;
    for(int i=1;i<=min;i++)
        if(n%i==0&&m%i==0)r1=i;
    printf("result=%d\nmethod2:\n",r1);
    int temp;
    while(n!=0){
        temp=m;
        m=n;
        n=temp%n;
    }
    printf("result=%d\n",m);
    return 0;
}
