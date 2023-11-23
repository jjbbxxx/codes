#include <stdio.h>
int  main(){
	
    float h,m,t,T;
    printf("请输入断电时间（时，分）：");
    scanf("%f%f",&h,&m);
	t=h+m/60;
	printf("温度为：");
	if(t>=11.9)printf("18℃");
	else{
    	T=(4*t*t)/(t+2)-20;
    	printf("%.3f℃",T);
    }
	return 0; 
} 
