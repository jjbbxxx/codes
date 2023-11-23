#include<stdio.h>
int main(){
	float c,f;
	printf("请输入一个华氏温度："); 
	scanf("%f",&f);
	c=5*(f-32)/9; 
	printf("对应的摄氏温度为：%.4f",c);
	
	return 0;
}
