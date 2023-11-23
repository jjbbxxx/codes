#include <stdio.h>
int  main(){
	int x=0;
	while(x==0){
	float S1,S2,S,t,v,h1,h2,m1,m2,s1,s2,h,m,s;
	printf("***所有输入均为整数***\n");
	printf("请输入起始里程：\n");
	scanf("%f",&S1);
	printf("请输入起始时间（时，分，秒）：\n");
	scanf("%f%f%f",&h1,&m1,&s1);
	printf("请输入结束里程：\n");
	scanf("%f",&S2);
	printf("请输入结束时间（时，分，秒）：\n");
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
	if(S<=0||t<=0)printf("数据有误！\n");
	else{ 
	x=1;
	v=S/t;
    printf("汽车行驶了%.0f公里\n共消耗消耗%.0f小时%.0f分%.0f秒\n平均速度为%.2f公里/小时",
	S,h,m,s,v);
	}
}
	return 0; 
} 
