#include<stdio.h>
int main()
{
    float w,s,t,p;
    int x=0;
    printf("请输入货物重量与托运距离：\n");
    scanf("%f %f",&w,&s);
    if(0<=s&&s<100)p=30;
    else if(100<=s&&s<200)p=27.5;
    else if(200<=s&&s<300)p=25;
    else if(300<=s&&s<400)p=22.5;
    else p=20;
 

    t=w*s*p;
    printf("总运费为：%.2f元\n",t);
    return 0;

}