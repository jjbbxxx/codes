#include<stdio.h>

int main()
{int x=0;
while(x==0){
    int y,m,d,yjg,dmax,err=0;
    printf("�����������գ�\n");
    scanf("%d %d %d",&y,&m,&d);
	   if(y%4!=0) yjg=0;
	   else if(y%100==0&&y%400!=0) yjg=0;
	   else yjg=1;
    if(m==1||m==3||m==5||m==7||m==8||m==10|m==12)dmax=31;
    else if(m==4||m==6||m==9||m==11)dmax=30;
    else if(m==2&&yjg==0)dmax=28;
    else if(m==2&&yjg==1)dmax=29;
    else err=1;
    if(d>dmax)err=2;
    if(err==1)printf("������·������⣬���飡\n");
    else if(err==2)printf("��������������⣬���飡\n");
    else { printf("%d��%d��%d������ȷ�����ڣ�\n",y,m,d);x=1;}  
    }
    
      
    return 0;
}
