#include<stdio.h>
#define pi 3.14
int main(){
	float d,h,c,s,v;
	printf("������Բ����ĵ���ֱ���͸ߣ��ÿո����������"); 
	scanf("%f %f",&d,&h);
	c=pi*d;
	s=(pi*d*d)/4;
	v=s*h;
	printf("Բ����ĵ����ܳ�Ϊ%.2f,�����Ϊ%.2f,���Ϊ%.2f.",c,s,v);
	
	return 0;
}
