#include <stdio.h>
int  main(){
	int x=0;
	while(x==0){
	float S1,S2,S,t,v,h1,h2,m1,m2,s1,s2,h,m,s;
	printf("***���������Ϊ����***\n");
	printf("��������ʼ��̣�\n");
	scanf("%f",&S1);
	printf("��������ʼʱ�䣨ʱ���֣��룩��\n");
	scanf("%f%f%f",&h1,&m1,&s1);
	printf("�����������̣�\n");
	scanf("%f",&S2);
	printf("���������ʱ�䣨ʱ���֣��룩��\n");
	scanf("%f%f%f",&h2,&m2,&s2);
	if(s2>=s1)s=s2-s1;
	else {
		s=s2+60-s1;
		m2-=1;
	}		
	if(m2>=m1)m=m2-m1;
	else{
		m=m2+60-m1;
		h2-=1;
	}
	h=h2-h1;
	t=h+m/60+s/3600;
	S=S2-S1;
	if(S<=0||t<=0)printf("��������\n");
	else{ 
	x=1;
	v=S/t;
    printf("������ʻ��%.0f����\n����������%.0fСʱ%.0f��%.0f��\nƽ���ٶ�Ϊ%.2f����/Сʱ",
	S,h,m,s,v);
	}
}
	return 0; 
} 
