#include <stdio.h>
int  main(){
	
    float h,m,t,T;
    printf("������ϵ�ʱ�䣨ʱ���֣���");
    scanf("%f%f",&h,&m);
	t=h+m/60;
	printf("�¶�Ϊ��");
	if(t>=11.9)printf("18��");
	else{
    	T=(4*t*t)/(t+2)-20;
    	printf("%.3f��",T);
    }
	return 0; 
} 
