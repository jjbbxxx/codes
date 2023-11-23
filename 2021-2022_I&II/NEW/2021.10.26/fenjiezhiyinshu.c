#include<stdio.h>
int main(){
    start:
    int a,t;
    printf("请输入一个数字：");
    scanf("%d",&a);
    int i;
    for(i=1;i<a;i++){
        if (a%i==0)t=i;
    }
    if(t==1){printf("%d是素数。\n",a);goto start;
	}
    else{
        printf("%d=",a);
        int temp=a,i=2;
        while(temp>1){
            while(i<=temp){
                if(temp%i==0){
                    temp/=i;
                    printf("%d*",i);
                    i--;
                }
            i++;
            }
        }
        printf("\b \n");

    }
   
    return 0;
}
