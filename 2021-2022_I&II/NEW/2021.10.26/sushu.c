#include<stdio.h>
int main(){
    int n,m;
    start:
    printf("������n,m(n<m)��");
    scanf("%d %d",&n,&m);
    if(n>=m){
        printf("�������������!\n");
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
    printf("\n%d~%d�乲��%d��������\n",n,m,count);
    return 0;
}
