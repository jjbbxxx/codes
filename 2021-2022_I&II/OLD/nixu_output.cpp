#include <stdio.h>
int  main(){
	
	int num,a,b,c,d,e;
	printf("请输入一个5位数：");
	scanf("%d",&num);
	a=num/10000;
	b=(num-10000*a)/1000;
	c=(num-10000*a-1000*b)/100;
	d=(num-10000*a-1000*b-100*c)/10;
	e=num-10000*a-1000*b-100*c-10*d;
	printf("%d-%d-%d-%d-%d",e,d,c,b,a);
	return 0; 
} 
