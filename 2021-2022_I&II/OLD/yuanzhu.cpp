#include<stdio.h>
#define pi 3.14
int main(){
	float d,h,c,s,v;
	printf("请输入圆柱体的底面直径和高（用空格键隔开）："); 
	scanf("%f %f",&d,&h);
	c=pi*d;
	s=(pi*d*d)/4;
	v=s*h;
	printf("圆柱体的底面周长为%.2f,表面积为%.2f,体积为%.2f.",c,s,v);
	
	return 0;
}
