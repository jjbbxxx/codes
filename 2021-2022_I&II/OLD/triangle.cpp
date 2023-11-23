#include <stdio.h>
#include <math.h>
int  main(){
	int x=0;
	while(x==0){
	
    float a,b,c,max,mina,minb;
    printf("请输入三角形的三个边：");
    scanf("%f%f%f",&a,&b,&c);
    if(a>b){
    	max=a;mina=b;
    }
    else{
    	max=b;mina=a;	
    } 
    if(c>max){
    	max=c;mina=a;minb=b;
    }
    else minb=c;
    if(mina+minb<=max){
    	printf("不能形成三角形！\n"); 
    }
    else{
    	float sin,cos,s;
    	cos=(mina*mina+minb*minb-max*max)/(2*mina*minb);
    	sin=sqrt(1-cos*cos);
    	s=mina*minb*sin/2;
    	printf("最大角正弦值为：%.3f\n三角形面积为：%.3f\n再见！",sin,s);
    	x=1;
    }
}
	return 0; 
} 
